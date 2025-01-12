### this a testcase for use with DOLFIN/FEniCS and PRAgMaTIc 
### by Kristian Ejlebjerg Jensen, January 2014, Imperial College London
### the purpose of the test case is to
### 1. derive two forcing terms that give orthogonal a step function solutions
### 2. solve a two poisson equations with the forcing terms using 2D anisotropic adaptivity
### (on the same mesh) using the inner ellipse method for combining the metrics
### 3. plot the resulting mesh and one of solutions.
### the width of the step, the number of solition<->adaptation iterations as well as the
### error level (eta) are optional input parameters

from fenics import *
from adaptivity import metric_pnorm, metric_ellipse, adapt
import matplotlib.pyplot as plt
from numpy import array, ones
from time import time

def check_metric_ellipse(width=2e-2, eta = 0.02, Nadapt=6):
    ### CONSTANTS
    meshsz = 40
    hd = Constant(width)
    ### SETUP MESH
    mesh = RectangleMesh(Point(-0.5,-0.5),Point(0.5,0.5),1*meshsz,1*meshsz,"left/right")
    ### SETUP SOLUTION
    angle = pi/8#rand()*pi/2 
    #testsol = 'tanh(x[0]/' + str(float(hd)) + ')' #tanh(x[0]/hd)
    testsol = 'tanh((' + str(cos(angle)) + '*x[0]+'+ str(sin(angle)) + '*x[1])/' + str(float(hd)) + ')' #tanh(x[0]/hd)
    ddtestsol = str(cos(angle)+sin(angle))+'*2*'+testsol+'*(1-pow('+testsol+',2))/'+str(float(hd)**2)
    #testsol2 = 'tanh(x[1]/' + str(float(hd)) + ')' #tanh(x[0]/hd)
    testsol2 = 'tanh((' + str(cos(angle)) + '*x[1]-'+ str(sin(angle)) + '*x[0])/' + str(float(hd)) + ')' #tanh(x[0]/hd)
    ddtestsol2 = str(cos(angle)-sin(angle))+'*2*'+testsol2+'*(1-pow('+testsol2+',2))/'+str(float(hd)**2)
    def boundary(x):
        return x[0]-mesh.coordinates()[:,0].min() < DOLFIN_EPS or mesh.coordinates()[:,0].max()-x[0] < DOLFIN_EPS \
        or mesh.coordinates()[:,1].min()+0.5 < DOLFIN_EPS or mesh.coordinates()[:,1].max()-x[1] < DOLFIN_EPS  

    for iii in range(Nadapt):
        V = FunctionSpace(mesh, "CG" ,2)
        dis = TrialFunction(V)
        dus = TestFunction(V)
        u = Function(V)
        u2 = Function(V)
        bc = DirichletBC(V, Expression(testsol, degree=2), boundary)
        bc2 = DirichletBC(V, Expression(testsol2, degree=2), boundary)
        R = interpolate(Expression(ddtestsol, degree=2),V)
        R2 = interpolate(Expression(ddtestsol2, degree=2),V)
        a = inner(grad(dis), grad(dus))*dx
        L = R*dus*dx
        L2 = R2*dus*dx
        solve(a == L, u, bc)
        solve(a == L2, u2, bc2)

        H  = metric_pnorm(u , eta, max_edge_length=1., max_edge_ratio=50);
        Mp =  project(H,  TensorFunctionSpace(mesh, "CG", 1))
        H2 = metric_pnorm(u2, eta, max_edge_length=1., max_edge_ratio=50);
        Mp2 = project(H2, TensorFunctionSpace(mesh, "CG", 1))
        H3 = metric_ellipse(H,H2)
        Mp3 = project(H3, TensorFunctionSpace(mesh, "CG", 1))
        print("H11: %0.0f, H22: %0.0f, V: %0.0f,E: %0.0f" % (assemble(abs(H3[0,0])*dx),assemble(abs(H3[1,1])*dx),mesh.num_vertices(),mesh.num_cells()))
        startTime = time()
        if iii != Nadapt-1:
            mesh, mf = adapt(Mp)
            mesh2, mf = adapt(Mp2)
            mesh3, mf = adapt(Mp3)
            
        print("total time was %0.1fs" % (time()-startTime))


    import os
    save_dir = 'output'
    if not os.path.exists(save_dir):
        os.makedirs(save_dir)

    # PLOT MESH
    plt.figure()
    plt.triplot(mesh.coordinates()[:,0],mesh.coordinates()[:,1],mesh.cells())
    plt.savefig(f'{save_dir}/minell_mesh.png')

    plt.figure()
    testf = interpolate(u2,FunctionSpace(mesh,'CG',1))
    vtx2dof = vertex_to_dof_map(FunctionSpace(mesh, "CG" ,1))
    zz = testf.vector()[vtx2dof]; zz[zz==1] -= 1e-16
    plt.tricontourf(mesh.coordinates()[:,0],mesh.coordinates()[:,1],mesh.cells(),zz,100)
    plt.savefig(f'{save_dir}/minell_sol.png')

if __name__=="__main__":
    check_metric_ellipse() 
