/*
Pedro Mota
Pledged
CSC 415 - Homework 6
2/6/23
*/

#include <iostream>
#include <math.h>
using namespace std;

float fx(float x){
    return exp(-x)-x;
}

float f1x(float x){
    return -exp(-x)-1;
}

void newton(float tol){
    float p0;
    cout << "What is the initial value?" << endl;
    cin >> p0;
    
    float h; 
    h = fx(p0)/f1x(p0);
    int i = 0;

    while(i <= 2){
        p0 = p0 - h;
        h = fx(p0)/f1x(p0);
        cout << "Value of p" << i << " :" << p0 << endl;
        i++;
    }
}

float fx2(float n){
    return pow(n, 3) - 2*pow(n, 2) - 5;
}

float f1x2(float n){
    return 3*pow(n,2) - 4*n;
}

void newton2(float tol){
    float p0;
    cout << "What is the initial value?" << endl;
    cin >> p0;

    float h;
    h = fx2(p0)/f1x2(p0);
    int i = 1;

    while(abs(h) >= tol){
        p0 = p0 - h;
        h = fx2(p0)/f1x2(p0);
        cout << "Iteration: " << i << endl;
        i++;
        cout << "Root: " << p0 << endl;
    }
}

int main(){
    cout << "What is the tolerance?\n";
    float tol;
    cin >> tol;
    cout << "Which problem do you want to solve?\n";
    cout << "A. Find p2 of f(x)= x^2-6\n";
    cout << "B. Find solutions accurate to within 0.0001 for: x^3 - 2x^2 -5\n";
    char a;
    cin >> a;
    switch(a){
        case 'A':
            newton(tol);
            break;
        
        case 'B':
            newton2(tol);
            break;
    
        default:
            cout << "Type A or B please\n";
            break;
    }
}

/* 
What is the initial value?
1
Value of p0 :3.5
Value of p1 :2.60714
Value of p2 :2.45426 
*/

/*
Iteration: 1
Root: -5
Iteration: 2
Root: -3.10526
Iteration: 3
Root: -1.79379
Iteration: 4
Root: -0.771264
Iteration: 5
Root: 0.594038
Iteration: 6
Root: -3.57758
Iteration: 7
Root: -2.1283
Iteration: 8
Root: -1.05602
Iteration: 9
Root: 0.0547433
Iteration: 10
Root: -23.7845
Iteration: 11
Root: -15.6431
Iteration: 12
Root: -10.2177
Iteration: 13
Root: -6.60111
Iteration: 14
Root: -4.18404
Iteration: 15
Root: -2.54864
Iteration: 16
Root: -1.38474
Iteration: 17
Root: -0.367138
Iteration: 18
Root: 2.47284
Iteration: 19
Root: 2.72228
Iteration: 20
Root: 2.69119
Iteration: 21
Root: 2.69065
*/