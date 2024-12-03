#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
    int num, base;
    string converted;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter base: ";
    cin >> base;
    int i = 0;
    while (num != 0) {
        int rem = num % base;
        converted += to_string(rem) + " ";
        num = num / base;
        i++;
    }
    reverse(converted.begin(), converted.end());

    cout << converted;
    return 0;
}
// #include <iostream>
// #include <algorithm>
// #include <stack>
// using namespace std;

// int main()
// {
//     stack<string> s;
//     int num, base;

//     cout << "Enter number: ";
//     cin >> num;
//     cout << "Enter base: ";
//     cin >> base;

//     while (num != 0)
//     {
//         int rem = num % base;
//         s.push(to_string(rem));
//         num = num / base;
//     }

//     while (!s.empty())
//     {
//         string str = s.top();
//         cout << str << " ";
//         s.pop();
//     }

//     return 0;
// }