/*
Pedro Mota
Pledged
2/1/23
Program 2: Bisection Method
*/

#include <iostream>
#include <math.h>
using namespace std;

double fx(double n);
void roots(double a , double b);

int main(){
    double a, b;
    cout << "Type the lower part of the interval: ";
    cin >> a;
    cout << "Type the higher part of the interval: ";
    cin >> b;
    roots(a, b);
    return 0;
}

double fx(double n){
    return -2.75*(n*n*n) + 18*(n*n) - 21*n - 12;
}

void roots(double a, double b){
    double c;
    c = a;
    int n = 0;
    while((b-a) >= 0.00001){
        c = (a+b)/2;
        if(fx(a)*fx(b) < 0){
            a = c;
        }else{
            b = c;
        }
        n++;
    }

    cout << "The root in this interval is: " << c << endl;
    cout << "The number of iterations is: " << n << endl;
}