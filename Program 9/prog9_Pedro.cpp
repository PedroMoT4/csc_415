#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define SIZE 20
float A[SIZE][SIZE];
float B[SIZE][SIZE];
float C[SIZE][SIZE];

int inputGraphA(){
    int i, j, n;
    ifstream fin;
    fin.open("matrix1.txt");
    fin >> n;
    for(i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fin >> A[i][j];
    return n;
}

int inputGraphB(){
    int i, j, n;
    ifstream fin;
    fin.open("matrix2.txt");
    fin >> n;
    for(i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fin >> B[i][j];
    return n;
}

void sum(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Sum: A + B" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
}

void diff(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "Difference: A - B" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
}

void prod(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0.0;
            for(int k = 0; k < n; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    cout << "Product: A*B" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int n = inputGraphA();
    cout << "Matrix A" << endl;
    cout << n << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    n = inputGraphB();
    cout << "Matrix B" << endl;
    cout << n << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }

    sum(n);
    diff(n);
    prod(n);
}