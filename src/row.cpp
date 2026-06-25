#include <iostream>
#include <vector>
#include "row.hpp"

row::row(int size){
row::size=size;    
for(int i=0;i<size;i++)
row::Row.push_back(frac());
}
void row::showRow(){
std::cout<<"[";
for(int i=0;i<size;i++)
{
row::Row[i].showFrac();
if(i!=(size-1))
cout<<",";
}
std::cout<<"]";
}
void row::subRow(row r){
for(int i=0;i<row::size;i++)
row::Row[i].subFrac(r.Row[i]);
}


bool row::normalizeRow(int indx){
if(row::Row[indx].isZero())
return false;
frac inv = row::Row[indx];
inv.invFrac();
for(int i=0;i<row::size;i++){
row::Row[i].mulFrac(inv);
}
return true;
}

frac row::getFrac(int indx){
return row::Row[indx];   
}

void row::mulScalar(frac scalar){
for(int i=0;i<row::size;i++)
row::Row[i].mulFrac(scalar);
}

void row::deleteIndx(int indx){
row::Row.erase(row::Row.begin() + indx);
size--;
}
bool row::allVarZero(){
for(int i=0;i<row::size-1;i++)
{if(!row::Row[i].isZero())
return false;}
return true;
}

void row::showEquation(int indx,vector<int> alias){
if(alias.size() != row::Row.size())
{
cout<<"cant show";
return;
}
cout<<"x"<<alias[indx]<<"=";
row::Row[row::size-1].showFrac();
cout<<"+";
frac n = frac(-1,1);
row::mulScalar(n);
for(int i=0;i<row::size-1;i++)
{
if(i!=indx && (!row::Row[i].isZero())){
cout<<"(";
row::getFrac(i).showFrac();
cout<<"*x"<<alias[i]<<")+";}
}
row::mulScalar(n);
}