/*
Pedro Mota - pledged
3/29/23
Program 7: Euler's Method
*/

#include <iostream>
#include <math.h>

using namespace std;


double f(double t, double w, int option){
    
    if(option == 1){
        return (w/t) - pow(2, (w/t));  
    }else if(option == 2){
        return 1 + w/t + pow(2, (w/t));
    }

}

void Euler(double a, double b, double h, double alpha, int p){
    double n = (b - a)/h;
    double t = a;
    double w = alpha;

    for(int i = 1; i <= n; i++){
        w = w + h * f(t, w, p);
        t = a + i*h;
        cout << "t = " << t << '\n' << "w = " << w << endl;
    }

}

int main(){
    double a, b, h, alpha;
    int p;
    cout << "What problem are you solving?" << endl << "1. y' = y/t - (y/t)^2" << endl
    << "2. y' = 1 + y/t +(y/t)^2\n";
    cin >> p;
    cout << "Value of t0: ";
    cin >> a;
    cout << "Value of ti: ";
    cin >> b;
    cout << "h value: ";
    cin >> h;
    cout << "Initial condition: ";
    cin >> alpha;
    Euler(a, b, h, alpha, p);
}