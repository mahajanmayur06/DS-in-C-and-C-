#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> res;
string str = "";

void generate (int i, int n) {
    if (str.size() == n) {
        res.push_back(str);
        return;
    }
    
    str.push_back('0');
    generate(i + 1, n);
    str.pop_back();
    if (str.back() == '1') {
        return;
    }
    str.push_back('1');
    generate(i + 1, n);
    str.pop_back();
}

int main()
{
    generate(0, 4);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}