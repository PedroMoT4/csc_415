/*
Pedro Mota - pledged
Program 11: Jacobi Method
5/1/23
*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define MAXSIZE 20
float a[MAXSIZE][MAXSIZE];
float x[MAXSIZE];
float b[MAXSIZE];
float x_old[MAXSIZE];

int inputGraph(){
    int i, j, n;
    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    for(i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fin >> a[i][j];
    return n;
}

float Distance(float x[], float y[], int n){
    float sum = 0.0;

    for(int i = 0; i < n; i++){
        sum = sum + (x[i] - y[i])* (x[i] - y[i]);
    }
    return sqrt(sum);
}

int main(){

    int n = inputGraph();
    cout << n << endl;
    int iter_num = 0;
    int i, j;

    cout << "******MATRIX******" << endl;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "\nInitial guess: ";
    for(i = 0; i < n; i++){
        b[i] = a[i][n-1];
        cout << b[i] << " ";
    }
    cout << "\n\n";

    do {
		iter_num++;
		for (i = 0; i < n; i++)
			x_old[i] = x[i];
		for (i = 0; i < n; i++){
			x[i] = b[i];
			for (j=1; j<i; j++)
				x[i] = x[i] - a[i][j]*x_old[j];

			for (j = i+1; j < n; j++){
                x[i] = x[i] - a[i][j]*x_old[j];
                x[i] = x[i]/a[i][i];
            }
		}
        cout << "Vector x" << iter_num <<endl;
        for (i = 0; i < n-1; i++)
            printf(" %f \n",x[i]);
        printf(" \n");

	}  while ((iter_num < 50) && (Distance(x_old, x, n) > .01));

}