#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int, int> map;
    map[4] = 4;
    map[5] = 2;
    map[8] = 0;
    map.erase(map[5]);
    cout << map.count(map[4]) << endl;
    cout << map.count(map[5]) << endl;

    map = {};
    cout << map.size();
    return 0;
}