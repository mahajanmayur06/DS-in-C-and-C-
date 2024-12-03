#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> str = {"999", "9999", "900", "800", "570", "5603", "9", "009", "057"};
    sort(str.begin(), str.end());
    for (string i : str) {
        cout << i << " ";
    }
    return 0;
} 