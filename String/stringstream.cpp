#include <bits/stdc++.h>
using namespace std;

string learn (string str) {
    stringstream ss;
    vector<int> arr = {2, 5, 6};
    int k = 0;
    for (int i = 0; i < str.size(); i++) {
        if (k < arr.size() && i == arr[k]) {
            ss << ' ';
            k++;
        }
        ss << str[i];
    }
    return ss.str();
}

void print (string str) {
    stringstream ss (str);
    string word;
    while (ss >> word) {
        cout << word; 
        cout << " ";
    }
}
int main()
{
    string str = "InTheMajesty";
    string res = learn(str);
    print(res);
    return 0;
}