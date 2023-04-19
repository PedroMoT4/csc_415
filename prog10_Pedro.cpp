/*
Pedro Mota - pledged
Program 10: Gaussian Elimination with Scaled Partial Pivoting
Test 1
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <cstdlib>
#include <math.h>
using namespace std;
#define SIZE 100
double A[SIZE][SIZE];
int n;

using namespace std;

int inputGraph(){
    int i, j, n;
    ifstream fin;
    fin.open("inputw.txt");
    fin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n+1; j++)
        fin >> A[i][j];
    
    fin.close();
    cout << "Initial matrix:" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n+1; j++){
            cout << "  " << A[i][j] << "  ";
        }
        cout << endl;
    }
    return n;
}

void gauss(int n){
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            double temp = A[j][i]/A[i][i];
            for(int k = i; k <= n+1; k++){
                A[j][k] = A[j][k] - A[i][k] * temp;
            }
        }
    }
}

void backsubs(int n){
    double b[n];
    for(int i = n-1; n < 0; i--){
        b[i] = A[i][n];
    }

    b[n] = A[n][n+1] / A[n][n];
    for(int i = n-1; i >= 1; i--){
        double sum = 0;
        for(int j = i+1; j <= n; j++){
            sum += A[i][j] * b[j];
        }
        b[i] = (A[i][n+1] - sum)/A[i][i];
    }

    cout << "Solution:" << endl;
    for(int i = 1; i <= n; i++){
        cout << "x[" << i << "] = " << b[i] <<  endl; 
    }
}

int main(){
    n = inputGraph();

    gauss(n);
    cout << "Matrix after Foward Elimination: \n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n+1; j++){
            if(abs(A[i][j]) < 0.000001){
                cout << "  " << 0 << "  "; 
            }else{
                cout << "  " << A[i][j] << "  ";
            }
        }
        cout << endl;
    }

    backsubs(n);
}