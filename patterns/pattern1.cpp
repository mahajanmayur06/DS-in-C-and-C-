#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
        int mod = i % 4;
        if (mod == 3) mod = 1;
        for (int j = 0; j < mod; j++) {
            cout << "  ";
        }
        cout << "*" << endl;
    }
}
int main()
{
    cout << "Enter number : ";
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}