#include "frac.hpp"
#include "row.hpp"
#include "matrix.hpp"
#include <iostream>
using namespace std;
int main() {
 matrix m = matrix(2,4);
m.showMatrix();
m.reduce();
cout<<endl;
m.showMatrix();
return 0;



}