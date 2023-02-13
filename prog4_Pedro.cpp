#include <iostream>
#include <math.h>
#define TOL 0.00001

using namespace std;

double fx(double x);
void steffensens(double p0, int n);

int main(){
    int n;
    double p0;

    cout << "What is the initial value: ";
    cin >> p0;

    cout << "Maximum number of iterations: ";
    cin >> n;

    steffensens(p0, n);

    return 0;
}

double fx(double x){
    return exp(-x);
}
 
void steffensens(double p0, int n){

    double p1, p2, p;
    int i = 1;

    while(i <= n){
        p1 = fx(p0);
        p2 = fx(p1);
        p = p0 - (p1 - p0)*(p1 - p0)/(p2 - 2*p1 + p0);

        if(abs(p - p0) < TOL){
            break;
        }
        p0 = p;
        i++; 
    }
    cout << "The root is: " << p << endl;
    cout << "It took " << i << " iterations." << endl;
}