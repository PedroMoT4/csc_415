#include <iostream>
#include <math.h>

using namespace std;


double f(double t, double w, int option){
    
    if(option == 1){
        return 1 + w/t;  
    }else if(option == 2){
        return cos(2*t) + sin(3*t);
    }else if(option == 3){
        return 1 + t*sin(t*w);
    }

}

double fp(double t, double y, int option){
    if(option == 1){
        return 1 + y/t + 1/t;
    }else if(option == 2){
        return cos(2*t) + sin(3*t);
    }else if(option == 3){
        return 1 + t*sin(t*y) - t * cos(t*y);
    }
}

void Taylor(double a, double b, double h, double alpha, int p){
    double n = (b - a)/h;
    double t = a;
    double w = alpha;

    for(int i = 1; i <= n; i++){
        w = w + h * f(t, w, p) + h * (h/2) * fp(t, w, p);
        t = a + i*h;
        cout << "t = " << t << '\n' << "w = " << w << endl;
    }

}

int main(){
    double a, b, h, alpha;
    int p;
    cout << "What problem are you solving?" << endl << "1. y' = 1 + y/t" << endl
    << "2. y' = cos(2t) + sin(3t)\n" << "3. y' = 1 + t*sin(ty)\n";
    cin >> p;
    cout << "Value of t0: ";
    cin >> a;
    cout << "Value of ti: ";
    cin >> b;
    cout << "h value: ";
    cin >> h;
    cout << "Initial condition: ";
    cin >> alpha;
    Taylor(a, b, h, alpha, p);
}