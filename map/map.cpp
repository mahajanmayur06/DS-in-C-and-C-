#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

void printMap(const map<int, string>& map) {
    for (const auto& pair : map) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}
void printMap2(const map<string, int>& map) {
    for (const auto& pair : map) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    // Ordered map
    map<int, string> orderedMap;
    map<string, int> mp;
    // Inserting elements
    // orderedMap[3] = "Three";
    // orderedMap[1] = "One";
    // orderedMap[4] = "Four";
    // orderedMap[2] = "Two";
    // orderedMap[5] = "Five";
    // orderedMap.insert(make_pair(-1, "Minus One"));
    // cout << "Map sorted by keys:\n";
    // printMap(orderedMap);
    mp.insert(make_pair("Mayur", 1000));
    mp.insert(make_pair("Shrihari", 90000));
    mp.insert(make_pair("Atharva", 10));
    mp.insert(make_pair("Ninad", 100));
    mp.insert(make_pair("Uday", 80));
    printMap2(mp);

    return 0;
}
