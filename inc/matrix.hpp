#pragma once
#include <vector>
#include "row.hpp"
class matrix{
public:
int m;
int n;
std::vector<row> Matrix;
std::vector<int> varsIndx;
bool changed;
bool reduced;
matrix(int m,int n);
void showMatrix();
bool putColumnZeros(int m,int n);
bool deleteZero(int m,int n);
void swapRows(int a,int b);
void deleteColumn(int n);
void deleteRow(int m);
void reduce();

};