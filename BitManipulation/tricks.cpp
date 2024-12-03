#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int a,int b){
    a = a ^ b;
    b = a ^ b; // a ^ b ^ b -> a ^ 0 -> a
    a = a ^ b; // a ^ b ^ a -> b ^ 0 -> b
    cout << a << " " << b << endl;
}

void getBit(int num, int i) {
    cout << ((num >> i) & 1);
}

void setBit(int num, int i){
    num = num | (1 << i);
    cout << num << endl;
}

void clearBit(int num, int i){
    num = num & ~(1 << i);
    cout << num << endl;
}

void toggleBit(int num, int i) {
    num = num ^ (1 << i);
    cout << num << endl;
}

void removeLastSetBit(int num) {
    num = num & (num - 1);
    cout << num << endl;
}

void power2(int num) {
    if (num & (num - 1) == 0){
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
}
int main()
{
    swap(3, 5);
    getBit(14, 1); // 1101
    setBit(13, 1); // 1101 -> 1111
    clearBit(14, 2); // 1110 -> 1010
    removeLastSetBit(14);
    removeLastSetBit(25);
    power2(16);
    return 0;
}