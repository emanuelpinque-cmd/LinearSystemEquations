#include <iostream>
#include "matrix.hpp"
#include "row.hpp"
matrix::matrix(int m,int n){
for(int i=0;i<m;i++){
this->m=m;
this->n=n;
this->changed=false;
this->reduced=false;
matrix::Matrix.push_back(row(n));
}
for(int i=0;i<matrix::n;i++)
matrix::varsIndx.push_back(i);

}

void matrix::showMatrix(){
for(int i=0;i<matrix::m;i++)
{
matrix:Matrix[i].showRow();
std::cout<<endl;
}

}

void matrix::swapRows(int a,int b){
row temp=matrix::Matrix[a];    
matrix::Matrix[a]=matrix::Matrix[b];
matrix::Matrix[b]=temp;
cout<<"rows has been swaped"<<endl;
matrix::showMatrix();
cout<<endl;
}

bool matrix::deleteZero(int m, int n){
    int row = m; // empieza desde m, no desde 0
    while(row < matrix::m)
    {
        if(!matrix::Matrix[row].getFrac(n).isZero()) // busca no-cero en fila row
        {
            if(row != m)
                matrix::swapRows(m, row);
            return true;
        }
        row++;
    }
    cout << "pivot not found" << endl;
    return false;
}

bool matrix::putColumnZeros(int m,int n){
if(!matrix::deleteZero(m,n))
return false;
matrix::Matrix[m].normalizeRow(n);
int actual_row=0;
while(actual_row<matrix::m){
if(actual_row!=m)
{
cout<<"row changed"<<endl;
matrix::showMatrix();
cout<<endl;
frac actualFrac = matrix::Matrix[actual_row].getFrac(n);
row r = matrix::Matrix[m];
r.mulScalar(actualFrac);
matrix::Matrix[actual_row].subRow(r);


}
actual_row++;
}
//matrix::showMatrix();
return true;
}
void matrix::deleteColumn(int n){
for(int i=0;i<matrix::m;i++)
matrix::Matrix[i].deleteIndx(n);
}

void matrix::deleteRow(int m){
matrix::Matrix.erase(matrix::Matrix.begin()+m);
matrix::m--;
}

void matrix::reduce(){
if(reduced)
return;

int i=0;
while(i<min(matrix::m,matrix::n))
{
if(!matrix::putColumnZeros(i,i))
{
matrix::n--;
matrix::varsIndx.erase(matrix::varsIndx.begin()+i);
matrix::deleteColumn(i);

matrix::showMatrix();
i=0; 
}
else{
matrix::showMatrix();
cout<<endl;
i++;
}
}

for(int i=0;i<matrix::m;i++)
{
if(matrix::Matrix[i].allVarZero())
{
if(matrix::Matrix[i].getFrac(matrix::n-1).isZero())
{
matrix::deleteRow(i);
changed=true;
}
else{
cout<<"no solution";
matrix::reduced=false;
for(int i=0;i<matrix::varsIndx.size();i++)
cout<<matrix::varsIndx[i];
return;
}}}
if(changed){
for(int i=0;i<min(matrix::m,matrix::n);i++)
matrix::Matrix[i].normalizeRow(i);
}

cout<<"reduced correctly"<<endl;
matrix::reduced=true;
for(int i=0;i<matrix::m;i++)
{matrix::Matrix[i].showEquation(i,matrix::varsIndx);
cout<<endl;
}}



