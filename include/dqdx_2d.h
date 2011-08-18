/*
 *    WARNING: Do not edit this file as it is automatically generated
 *             and may be overwritten. Instead, merge your changes into
 *             sage/functional.sage and execute make from there. You will
 *             need sage in your PATH for this to work. If you commit your
 *             changes then commit both sage/functional.sage and the
 *             generated files.
 *
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

  void grad_r(
              real_t a0, real_t a1, real_t a2, real_t a3, real_t a4, real_t a5,
              real_t b0, real_t b1, real_t b2, real_t b3, real_t b4, real_t b5,
              real_t c0, real_t c1, real_t c2, real_t c3, real_t c4, real_t c5,
              real_t x1, real_t y1, real_t m00_1, real_t m01_1, real_t m11_1,
              real_t x2, real_t y2, real_t m00_2, real_t m01_2, real_t m11_2,
              real_t *grad){
    grad[0] = 1.26424253333333*(x1*y2 - x2*y1)*SQRT(1/(double)9*(c5 + m11_1 + m11_2)*(a5 + m00_1 + m00_2) - 1/(double)9*pow((b5 + m01_1 + m01_2), 2))*(((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1 - (b4*x1 + c4*y1 - b5 - m01_1 - m01_2)*y1 - (a4*x1 + b4*y1 - a5 - m00_1 - m00_2)*x1)/(double)SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + ((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2 - (b4*x2 + c4*y2 - b5 - m01_1 - m01_2)*y2 - (a4*x2 + b4*y2 - a5 - m00_1 - m00_2)*x2)/(double)SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) - ((y1 - y2)*((y1 - y2)*c4 + (x1 - x2)*b4) + (x1 - x2)*((y1 - y2)*b4 + (x1 - x2)*a4))/(double)SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))))*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)/(double)((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000)*((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000) + 3.79272760000000*(y1 - y2)*SQRT(1/(double)9*(c5 + m11_1 + m11_2)*(a5 + m00_1 + m00_2) - 1/(double)9*pow((b5 + m01_1 + m01_2), 2))/(double)((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000) + 0.210707088888889*(x1*y2 - x2*y1)*((c5 + m11_1 + m11_2)*a4 - 2*(b5 + m01_1 + m01_2)*b4 + (a5 + m00_1 + m00_2)*c4)/(double)(((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000)*SQRT(1/(double)9*(c5 + m11_1 + m11_2)*(a5 + m00_1 + m00_2) - 1/(double)9*pow((b5 + m01_1 + m01_2), 2)));
    grad[1] = 1.26424253333333*(x1*y2 - x2*y1)*SQRT(1/(double)9*(c5 + m11_1 + m11_2)*(a5 + m00_1 + m00_2) - 1/(double)9*pow((b5 + m01_1 + m01_2), 2))*(((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1 - (b3*x1 + c3*y1 - c5 - m11_1 - m11_2)*y1 - (a3*x1 + b3*y1 - b5 - m01_1 - m01_2)*x1)/(double)SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + ((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2 - (b3*x2 + c3*y2 - c5 - m11_1 - m11_2)*y2 - (a3*x2 + b3*y2 - b5 - m01_1 - m01_2)*x2)/(double)SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) - ((y1 - y2)*((y1 - y2)*c3 + (x1 - x2)*b3) + (x1 - x2)*((y1 - y2)*b3 + (x1 - x2)*a3))/(double)SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))))*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)/(double)((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000)*((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000) - 3.79272760000000*(x1 - x2)*SQRT(1/(double)9*(c5 + m11_1 + m11_2)*(a5 + m00_1 + m00_2) - 1/(double)9*pow((b5 + m01_1 + m01_2), 2))/(double)((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000) + 0.210707088888889*(x1*y2 - x2*y1)*((c5 + m11_1 + m11_2)*a3 - 2*(b5 + m01_1 + m01_2)*b3 + (a5 + m00_1 + m00_2)*c3)/(double)(((SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000)*(SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y1 + (a5 + m00_1 + m00_2)*x1)*x1 + 1/(double)3*((c5 + m11_1 + m11_2)*y1 + (b5 + m01_1 + m01_2)*x1)*y1) + SQRT(1/(double)3*((b5 + m01_1 + m01_2)*y2 + (a5 + m00_1 + m00_2)*x2)*x2 + 1/(double)3*((c5 + m11_1 + m11_2)*y2 + (b5 + m01_1 + m01_2)*x2)*y2) + SQRT(1/(double)3*(y1 - y2)*((y1 - y2)*(c5 + m11_1 + m11_2) + (x1 - x2)*(b5 + m01_1 + m01_2)) + 1/(double)3*(x1 - x2)*((y1 - y2)*(b5 + m01_1 + m01_2) + (x1 - x2)*(a5 + m00_1 + m00_2))) - 1.50000000000000) + 1.89199003000000)*SQRT(1/(double)9*(c5 + m11_1 + m11_2)*(a5 + m00_1 + m00_2) - 1/(double)9*pow((b5 + m01_1 + m01_2), 2)));
    
    return;
  }