#pragma once
#include <vector>
#include "frac.hpp"
using namespace std;
class row{
public:
vector <frac> Row;
int size;

row(int size);

void showRow();

void subRow(row R);

bool normalizeRow(int indx);

frac getFrac(int indx);

void mulScalar(frac scalar);

void deleteIndx(int indx);

bool allVarZero();

void showEquation(int indx,vector<int> alias);

};