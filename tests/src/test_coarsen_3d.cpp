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
#include <iostream>
#include <vector>

#include <omp.h>

#include "Mesh.h"
#include "Surface.h"
#include "VTKTools.h"
#include "MetricField.h"
#include "Smooth.h"
#include "Coarsen.h"
#include "ticker.h"

using namespace std;

int main(int argc, char **argv){
  Mesh<double, int> *mesh=VTKTools<double, int>::import_vtu("../data/box10x10x10.vtu");

  Surface<double, int> surface(*mesh);

  MetricField<double, int> metric_field(*mesh, surface);

  size_t NNodes = mesh->get_number_nodes();

  vector<double> psi(NNodes, 0);
  
  metric_field.add_field(&(psi[0]), 1.0);
  metric_field.update_mesh();
  
  Coarsen<double, int> adapt(*mesh, surface);
  Smooth<double, int> smooth(*mesh, surface);

  double L_up = sqrt(2.0);
  double L_low = L_up*0.5;

  double tic = get_wtime();
  adapt.coarsen(L_low, L_up);
  double toc = get_wtime();

  double lrms = mesh->get_lrms();
  double qrms = mesh->get_qrms();

  mesh->verify();

  std::map<int, int> active_vertex_map;
  mesh->defragment(&active_vertex_map);
  surface.defragment(&active_vertex_map);
  
  int nelements = mesh->get_number_elements();  

  std::cout<<"Coarsen loop time:     "<<toc-tic<<std::endl
           <<"Number elements:      "<<nelements<<std::endl
           <<"Edge length RMS:      "<<lrms<<std::endl
           <<"Quality RMS:          "<<qrms<<std::endl;


  VTKTools<double, int>::export_vtu("../data/test_coarsen_3d", mesh);
  VTKTools<double, int>::export_vtu("../data/test_coarsen_3d_surface", &surface);
  
  if((nelements<60)&&(lrms<0.4)&&(qrms<1.1))
    std::cout<<"pass"<<std::endl;
  else
    std::cout<<"fail"<<std::endl;
  
  delete mesh;

  return 0;
}
