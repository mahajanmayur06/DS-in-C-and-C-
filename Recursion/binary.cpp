#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string decimalToBinary (int num) {
    if (num == 0) {
        return "";
    }
    return decimalToBinary(num / 2) + to_string(num % 2);
}
int main()
{
    string binary = decimalToBinary(14);
    cout << "string " << binary;
    return 0;
}