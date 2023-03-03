/*
Program 5
Pedro Mota - pledged
Composite Simpson's Rule
*/

#include <iostream>
#include <math.h>

using namespace std;

double fx(double x){
    return 1/(x+4);
}

//Composite Simpson's Rule
double simpsons(double a, double b, int n){
    double h = (b-a)/n;
    double xi0 = fx(a) + fx(b);
    double xi1 = 0, xi2 = 0;
    int counter = 0;

    for(int i = 1; i < n; i++){
        double x = a + i*h;
        if(i % 2 == 0){
            xi2 = xi2 + fx(x);
            counter++;
        }else{
            xi1 = xi1 + fx(x);
            counter++;
        }
    }

    double xi = h*(xi0 + 2*xi2 + 4*xi1)/3;
    cout << "Composite Simpson's Rule: " << xi << endl;
    cout << "It took: " << counter << " loop iterations" << endl;
}

int main(){
    double a, b, n;
    cout << "Lower limit: ";
    cin >> a;
    cout << "Upper limit: ";
    cin >> b;
    cout << "n: ";
    cin >> n;
    simpsons(a, b, n);
    return 0;
}