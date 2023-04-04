/*
Pedro Mota - pledged
Program 8: Runge-Kutta
4/5/23
*/

#include <iostream>
#include <math.h>

using namespace std;

double fx(double t, double y){
    return sin(y) + exp(-t);
}

void runge(double a, double b, double h, double alpha){
    double n = (b - a)/h;
    double t = a;
    double w = alpha;

    for(int i = 1; i <= n; i++){
        double k1 = h*fx(t, w);
        double k2 = h*fx(t + h/2, w + k1/2);
        double k3 = h*fx(t + h/2, w + k2/2);
        double k4 = h*fx(t + h, w + k3);

        w = w + (k1 + 2*k2 + 2*k3 + k4)/6;
        t = a + i*h;

        cout << "w" << i << ": " << w << " | ";
        cout << "t" << i << ": " << t << endl;
    }

}

int main(){
    double a, b, h, alpha;

    cout << "Value of t0: ";
    cin >> a;
    cout << "Value of ti: ";
    cin >> b;
    cout << "h value: ";
    cin >> h;
    cout << "Initial condition: ";
    cin >> alpha;

    runge(a, b, h, alpha);
}