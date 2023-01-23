/*
Pedro Mota
Pledged
1/23/23
Program 1: pi approximation
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double u = 2;
    double v = 1/sqrt(2);
    int counter = 0;

    u = u/v;
    v = sqrt((1+v)/2);
    
    while(u < 3.14159){
        u = u/v;
        cout << "u: " << u << endl;
        v = sqrt((1+v)/2);
        cout << "v: " << v << endl;
        cout << endl;
        counter++;
    }

    cout << counter << " iterations" << endl;

    return 0;
}