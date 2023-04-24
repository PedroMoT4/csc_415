/*
Optional Homework
Pedro Mota - Pledged
4/24/23
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#define SIZE 100
double A[SIZE][SIZE];
int n;

using namespace std;

int inputGraph(){
    int i, j, n;
    ifstream fin;
    fin.open("opt_hmw2.txt");
    fin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        fin >> A[i][j];
    
    fin.close();
    cout << "Initial matrix:" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
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

void print(int n){
    cout << "\nGauss Elimination matrix:\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(abs(A[i][j]) < 0.000001){
                cout << "  " << 0 << "  "; 
            }else{
                cout << "  " << A[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

double determinant(int n){
    double det = 1;
    for(int i = 1; i <= n; i++){
        det = det * A[i][i];
    }

    if(det < 0){
        det = det * (-1);
    }

    return det;
}

int main(){

    int n;
    n = inputGraph();
    gauss(n);
    print(n);
    cout << "\nDeterminant: " << determinant(n);
}