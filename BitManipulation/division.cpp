#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    int quo = 0;
    int rem = dividend;
    int newDiv;
    if (divisor < 0) {
        newDiv = ~divisor + 1;
    }
    else {
        newDiv = divisor;
    }
    while (rem > newDiv || rem != 0)
    {
        rem -= newDiv;
        if (quo < INT_MIN + 1)
            return INT_MIN;
        if (quo > INT_MAX - 1)
            return INT_MAX;
        quo++;
    }
    return divisor > 0 ? quo : -1 *  quo;
}

int main()
{
    cout << divide(7, -3);
    return 0;
}