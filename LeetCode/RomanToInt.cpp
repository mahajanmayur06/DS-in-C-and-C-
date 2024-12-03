#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> map = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int num = 0;
    int i = 0;
    while (i < s.size())
    {
        if (i < s.size() - 1 && map[s[i]] < map[s[i + 1]])
        {
            num += map[s[i + 1]] - map[s[i]];
            i += 2;
        }
        else
        {
            num += map[s[i]];
            i++;
        }
    }
    return num;
}
int main()
{
    cout << romanToInt("MCMXCIV") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("XIIV") << endl;
    return 0;
}