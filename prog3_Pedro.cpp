/*
Pedro Mota
Pledged
Program 3: Newton's method
2/9/23
*/

#include <iostream>
#include <math.h>
using namespace std;
#define TOL 0.00001


double fxa(double x){
    return exp(x)+pow(2,-x)+2*cos(x)-6;
}

double f1xa(double x){
    return exp(x)-log(2)*pow(2,-x)-2*sin(x);
}

void newtonA(double p0){

    float h; 
    h = fxa(p0)/f1xa(p0);
    int i = 1;

    while(abs(h) >= TOL){
        p0 = p0 - h;
        h = fxa(p0)/f1xa(p0);
        i++;
    }

    cout.precision(20);
    cout << "Method completed after: " << i << " iterations" << endl;
    cout << "The root is: " << p0; 
}

double fxb(double x){
    return 2*x*cos(2*x) - pow(x-2,2); 
}

double f1xb(double x){
    return -2*x + 2*(-2*x*sin(2*x) + cos(2*x)) + 4;
}

void newtonB(double p0){

    float h; 
    h = fxb(p0)/f1xb(p0);
    int i = 1;

    while(abs(h) >= TOL){
        p0 = p0 - h;
        h = fxb(p0)/f1xb(p0);
        i++;
    }

    cout.precision(20);
    cout << "Method completed after: " << i << " iterations" << endl;
    cout << "The root is: " << p0; 
}

double fxc(double x){
    return exp(x) - 3*pow(x,2);
}

double f1xc(double x){
    return exp(x)-6*x;
}

void newtonC(double p0){

    float h; 
    h = fxc(p0)/f1xc(p0);
    int i = 1;

    while(abs(h) >= TOL){
        p0 = p0 - h;
        h = fxc(p0)/f1xc(p0);
        i++;
    }

    cout.precision(20);
    cout << "Method completed after: " << i << " iterations" << endl;
    cout << "The root is: " << p0; 
}

double fxd(double x){
    return sin(x) - exp(x);
}

double f1xd(double x){
    return cos(x)-exp(x);
}

void newtonD(double p0){

    float h; 
    h = fxd(p0)/f1xd(p0);
    int i = 1;

    while(abs(h) >= TOL){
        p0 = p0 - h;
        h = fxd(p0)/f1xd(p0);
        i++;
    }

    cout.precision(20);
    cout << "Method completed after: " << i << " iterations" << endl;
    cout << "The root is: " << p0; 
}


int main(){

    double p0;

    cout << "\ne^x + 2^(-x) + 2*cos(x)-6" << endl;
    cout << "What is the initial value?" << endl;
    cin >> p0;
    newtonA(p0);
    cout << endl;

    cout << "\n2x*cos(2x)-(x-2)^2" <<endl;
    cout << "What is the initial value?" << endl;
    cin >> p0;
    newtonB(p0);
    cout << endl;
    cout << "What is the initial value for the 2nd interval?" << endl;
    cin >> p0;
    newtonB(p0);

    cout << "\ne^x - 3x^2" <<  endl;
    cout << "What is the initial value?" << endl;
    cin >> p0;
    newtonC(p0);
    cout << endl;
    cout << "What is the initial value for the 2nd interval?" << endl;
    cin >> p0;
    newtonC(p0);


    cout << "\nsin(x)-e^x" << endl;
    cout << "What is the initial value?" << endl;
    cin >> p0;
    newtonD(p0);
    cout << endl;
    cout << "What is the initial value for the 2nd interval?" << endl;
    cin >> p0;
    newtonD(p0);
    cout << endl;
    cout << "What is the initial value for the 3rd interval?" << endl;
    cin >> p0;
    newtonD(p0);
}