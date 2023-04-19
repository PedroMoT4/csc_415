/*
Pedro Mota - pledged
Program 10: Gaussian Elimination with Scaled Partial Pivoting
*/
/* #include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>

using namespace std;

#define SIZE 20
float A[SIZE][SIZE];


int inputGraphA(string c){
    int i, j, n;
    ifstream fin;
    fin.open(c);
    fin >> n;
    for(i = 0; i < n; i++)
        for (j = 0; j < n+1; j++)
            fin >> A[i][j];
    return n;
}

int inputGraphNxN(string c){
    int i, j, n;
    ifstream fin;
    fin.open(c);
    fin >> n;
    for(i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fin >> A[i][j];
    return n;
}

void printGraph(int n){
    cout << "System of equations" << endl;
    cout << n << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n+1; j++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}

void printGraphNxN(int n){
    cout << "System of equations" << endl;
    cout << n << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}

void gauss(int n){
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n+1; j++){
            double temp = A[j][i]/A[i][i];
            for(int k = i; k <= n+2; k++){
                A[j][k] = A[j][k] - A[i][k] * temp;
            }
        }
    }
}

void gaussNxN(int n){
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
    int option, n;
    string c;

    cout << "Is the input a NxN matrix?" << endl <<"1.Yes" << endl <<"2.No" << endl;
    cin >> option;

    if(option == 1){
        cout << "What is the name of the file?" << endl;
        cin >> c;
        n = inputGraphNxN(c);
        printGraphNxN(n);
        gaussNxN(n);
    }else if(option == 2){
        cout << "What is the name of the file?" << endl;
        cin >> c;
        n = inputGraphA(c);
        printGraph(n);
        gauss(n);
    }else{
        cout << "Invalid option" << endl;
    }

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
} */
/*
Pedro Mota - pledged
3/30/23
Program 7 - Gauss Elimination
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