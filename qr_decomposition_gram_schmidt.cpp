//Add if necessary
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <iomanip>



using namespace std;

int main () {


    /* input data for QR decomposition */
    double input_mat[][5] = {
        {2.3, -2.1, 8.0, 5.0, -4.1},
        {2.8, 1.3, 1.0, -9.2, -1.0},
        {1.1, 2.9, 3.1, -2.1, 5.1},
        {-2.1, -6.0, -2.1, 2.0, 3.0},
        {7.0, 0.5, -2.1, 2.0, -5.0},
    };




    /* print the input_mat before calling gramSchmidt_QRdecomposition */
    std::cout << "input_mat = " << std::endl;
    std::cout << std::endl;
    // write here...
  int i,j,k;
  
  for(i=0;i<5;++i){
    for(j=0;j<5;++j){
        cout << fixed << setprecision(3) << setw(7) << input_mat[i][j];
    }
    cout << endl;
  }
  cout << endl;



    // Gram-Schmidt & QR decomposition
    // write here...
  double Q[5][5], R[5][5], U[5][5];

  for(j=0;j<5;++j){
    for(i=0;i<5;++i){
      U[i][j]=input_mat[i][j];
    }
  }
 
  for(j=0;j<5;++j){
    for(i=0;i<j;++i){
        double r = 0;
        for(k=0;k<5;++k){
            r += Q[k][i] * U[k][j];
        }
        R[i][j] = r;
        for(k=0;k<5;++k) {
            U[k][j]-=r*Q[k][i];
        }
    }

      double norm = 0;
      for(k=0;k<5;++k){
          norm+=U[k][j]*U[k][j];
      }
      norm = sqrt(norm);
      for(k=0;k<5;++k){
          Q[k][j] = U[k][j]/norm;
      }
      R[j][j] = norm;
  }


    /* print the matrix Q resulting from gramSchmidt_QRdecomposition */
    std::cout << "Q = " << std::endl;
    std::cout << std::endl;
    // write here...
  for(i=0;i<5;++i){
    for(j=0;j<5;++j){
        cout << fixed << setprecision(3) << setw(7) << Q[i][j];
    }
    cout << endl;
  }
  cout << endl;


    /* print the matrix R resulting from gramSchmidt_QRdecomposition */
    std::cout << "R = " << std::endl;
    std::cout << std::endl;
    // write here...
  for(i=0;i<5;++i){
    for(j=0;j<5;++j){
        cout << fixed << setprecision(3) << setw(7) << R[i][j];
    }
    cout << endl;
  }
  cout << endl;


    /* print the matrix Q * R */
    std::cout << "Q * R = ?" << std::endl;
    std::cout << std::endl;
    // write here...
    double QR[5][5];
    for(i=0;i<5;++i){
      for(j=0;j<5;++j){
          for(k=0;k<5;++k){
            QR[i][j] += Q[i][k]*R[k][j];
            }
        }
    }
  for(i=0;i<5;++i){
      for(j=0;j<5;++j){
          cout << fixed << setprecision(3) << setw(7) << QR[i][j];
      }
      cout << endl;
  }
  cout << endl;



    /* print Input_mat - (Q * R) */
    std::cout << "Input_mat - (Q * R) = ?" << std::endl;
    std::cout << std::endl;
    // write here...
    double diff[5][5];
    for(i=0;i<5;++i){
        for(j=0;j<5;++j){
            diff[i][j] = input_mat[i][j]-QR[i][j];
    }
  }
  for(i=0;i<5;++i){
    for(j=0;j<5;++j){
      cout << fixed << setprecision(3) << setw(7) << diff[i][j];
    }
    cout << endl;
  }
  cout << endl;



    return 0;
}
