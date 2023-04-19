#include<iostream>
#include <fstream>
#include  <cstdlib>
using namespace std;


#define SIZE 20
float A[SIZE][SIZE];
float B[SIZE][SIZE];

int main()
{
int i, j, n;
ifstream fin;
fin.open("matrixA.txt");
fin >> n;
for(i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		fin >> A[i][j];

for (i = 0; i < n; i++)
	{
	for (j = 0; j < n; j++)
	     cout << A[i][j] << ' ';
	cout << endl;
    }

}
