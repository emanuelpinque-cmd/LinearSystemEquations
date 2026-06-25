#pragma once
class frac {
    int a;
    int b;

public:
    frac ();
    frac(int a, int b);
    void sumFrac(frac f2);
    void subFrac(frac f2);
    void mulFrac(frac f2);
    void showFrac();
    void invFrac();
    void simFrac();
    void buildFrac();
    bool isZero();
};