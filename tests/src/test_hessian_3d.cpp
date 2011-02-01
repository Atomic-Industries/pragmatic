/* 
 *    Copyright (C) 2010 Imperial College London and others.
 *    
 *    Please see the AUTHORS file in the main source directory for a full list
 *    of copyright holders.
 *
 *    Gerard Gorman
 *    Applied Modelling and Computation Group
 *    Department of Earth Science and Engineering
 *    Imperial College London
 *
 *    amcgsoftware@imperial.ac.uk
 *    
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation,
 *    version 2.1 of the License.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *    USA
 */
#include <vtkUnstructuredGrid.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkCell.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>

#include <iostream>
#include <vector>

#include "MetricField.h"
#include "Surface.h"

using namespace std;

int main(int argc, char **argv){
  vtkXMLUnstructuredGridReader *reader = vtkXMLUnstructuredGridReader::New();
  reader->SetFileName("../data/box20x20x20.vtu");
  reader->Update();

  vtkUnstructuredGrid *ug = reader->GetOutput();

  int NNodes = ug->GetNumberOfPoints();
  int NElements = ug->GetNumberOfCells();

  vector<double> x(NNodes),  y(NNodes), z(NNodes);
  for(int i=0;i<NNodes;i++){
    double r[3];
    ug->GetPoints()->GetPoint(i, r);
    x[i] = r[0];
    y[i] = r[1];
    z[i] = r[2];
  }

  vector<int> ENList;
  for(int i=0;i<NElements;i++){
    vtkCell *cell = ug->GetCell(i);
    for(int j=0;j<4;j++){
      ENList.push_back(cell->GetPointId(j));
    }
  }

  Mesh<double, int> mesh(NNodes, NElements, &(ENList[0]), &(x[0]), &(y[0]), &(z[0]));

  Surface<double, int> surface(mesh);

  MetricField<double, int> metric_field(mesh, surface);

  vector<double> psi(NNodes);
  for(int i=0;i<NNodes;i++)
    psi[i] = x[i]*x[i]+y[i]*y[i]+z[i]*z[i];
  
  double start_tic = omp_get_wtime();
  metric_field.add_field(&(psi[0]), 1.0);
  std::cerr<<"Hessian loop time = "<<omp_get_wtime()-start_tic<<std::endl;

  vector<double> metric(NNodes*9);
  metric_field.get_metric(&(metric[0]));
  
  vtkUnstructuredGrid *ug_out = vtkUnstructuredGrid::New();
  ug_out->DeepCopy(ug);
  
  vtkDoubleArray *mfield = vtkDoubleArray::New();
  mfield->SetNumberOfComponents(9);
  mfield->SetNumberOfTuples(NNodes);
  mfield->SetName("Metric");
  double rms[] = {0., 0., 0.,
                  0., 0., 0.,
                  0., 0., 0.};
  for(int i=0;i<NNodes;i++){
    rms[0] += pow(2.0-metric[i*9  ], 2);
    rms[1] += pow(metric[i*9+1], 2);
    rms[2] += pow(metric[i*9+2], 2);
    
    rms[3] += pow(metric[i*9+3], 2);
    rms[4] += pow(2.0-metric[i*9+4], 2);
    rms[5] += pow(metric[i*9+5], 2);
    
    rms[6] += pow(metric[i*9+6], 2);
    rms[7] += pow(metric[i*9+7], 2);
    rms[8] += pow(2.0-metric[i*9+8], 2);

    mfield->SetTuple9(i,
                      metric[i*9],   metric[i*9+1], metric[i*9+2],
                      metric[i*9+3], metric[i*9+4], metric[i*9+5],
                      metric[i*9+6], metric[i*9+7], metric[i*9+8]);
  }
  ug_out->GetPointData()->AddArray(mfield);

  double max_rms = 0;
  for(size_t i=0;i<9;i++){
    rms[i] = sqrt(rms[i]/NNodes);
    max_rms = std::max(max_rms, rms[i]);
  }

  if(max_rms>0.01)
    std::cout<<"fail\n";
  else
    std::cout<<"pass\n";

  vtkDoubleArray *scalar = vtkDoubleArray::New();
  scalar->SetNumberOfComponents(1);
  scalar->SetNumberOfTuples(NNodes);
  scalar->SetName("psi");
  for(int i=0;i<NNodes;i++)
    scalar->SetTuple1(i, psi[i]);
  ug_out->GetPointData()->AddArray(scalar);

  vtkXMLUnstructuredGridWriter *writer = vtkXMLUnstructuredGridWriter::New();
  writer->SetFileName("../data/test_hessian_3d.vtu");
  writer->SetInput(ug_out);
  writer->Write();

  return 0;
}
