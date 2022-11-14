//#include "racional.hpp"

#include <iostream>
using namespace std;

int mcd(int a, int b)
{
    // s'hauria de modificar i provar la funció gcd()
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

void simplificarRacional(int num, int den)
{
    //modificar per provar el reduce()
    if (den > 1)
    {
        int x = mcd(num, den);
        num /= x;
        den /= x;
    }
    cout << num << "/" << den << endl;
}

int main()
{
    int num, den;
    cin >> num >> den;

    simplificarRacional(num, den);
}