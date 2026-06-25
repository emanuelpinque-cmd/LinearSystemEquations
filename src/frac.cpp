#include "frac.hpp"
#include <iostream>
using namespace std;

frac::frac(int a, int b) {
    this->a = a;
    this->b = b;
}

frac::frac(){
int a,b;
cin>>a;
this->a=a;
this->b=1;
}
void frac::sumFrac(frac f2) {
    *this = frac(this->a * f2.b + f2.a * this->b, this->b * f2.b);
    this->simFrac();
}


void frac::subFrac(frac f2){
    *this = frac(this->a * f2.b - f2.a * this->b, this->b * f2.b);
    this->simFrac();
}

void frac::mulFrac(frac f2) {
    *this = frac(this->a * f2.a, this->b * f2.b);
    this->simFrac();
}

void frac::showFrac() {
    if (this->a == 0 && this->b == 0)
        cout << "error";
    else if (this->a == 0)
        cout << "0";
    else if (this->b == 0)
        cout << "infty";
    else {
        if (!(this->a > 0 == this->b > 0))
            cout << "-";
        if (abs(this->a) == abs(this->b))
            cout << "1";
        else
            cout << abs(this->a) << "/" << abs(this->b);
    }
}

void frac::invFrac() {
    int temp = this->a;
    this->a = this->b;
    this->b = temp;
}

void frac::simFrac() {
    int x = abs(a), y = abs(b);
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    a /= x;
    b /= x;
}
bool frac::isZero(){
if((frac::a==0)&&(frac::b!=0))
return true;
return false;
}
