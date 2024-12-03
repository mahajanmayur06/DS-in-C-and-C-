#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int num = 0;
        while (x != 0) {
            if (num > INT_MAX / 10 || num < INT_MIN / 10) {
                return 0;
            }
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }
};

int main()
{
    Solution obj = Solution();
    int num = obj.reverse(12345678999);
    cout << num;
    return 0;
}