/*
Pedro Mota
Pledged
Program 6: Adaptive Quadrature
*/

#include <iostream>
#include <math.h>

using namespace std;

double app = 0, tol = 0.00001;

double fx(double x){
    return x * sin(x * x);
}

double S(double a, double b){
    double h = (b-a)/2;
    return h*(fx(a) + 4*(fx(a+h)) + fx(b))/3;
}

void adaptive(double a, double b, double s0, double tol){
    double m = (a+b)/2;
    double s1 = S(a,m), s2 = S(m, b);
    if(abs(s0 - s1 - s2) < 10*tol){
        app = app + s1 + s2;
    }else{
        adaptive(a, m, s1, tol/2);
        adaptive(m, b, s2, tol/2);
    }

    cout << "Adaptive Quadrature: " << app << endl;
}

int main(){
    double a, b;
    cout << "Insert the lower bound: ";
    cin >> a;
    cout << "Insert the upper bound: ";
    cin >> b;
    double s0 = S(a, b);

    adaptive(a, b, s0, tol);
}