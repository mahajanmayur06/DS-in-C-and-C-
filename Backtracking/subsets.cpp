#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout  << ", ";
    }
    cout << "}" << endl;
}

// using recursion :
void recursion (vector<int> &vec, vector<int> res, int ind) {
    if (ind >= vec.size())
    {
        printVector(res);
        return;
    }
    subSequences(vec, res, ind + 1); // Not to take last element
    res.push_back(vec[ind]);
    subSequences(vec, res, ind + 1); //  To add elements
}

// using backtracking
void subSequences(vector<int> &vec, vector<int> &res, int ind)
{
    if (ind >= vec.size())
    {
        printVector(res);
        return;
    }
    res.push_back(vec[ind]);
    subSequences(vec, res, ind + 1); //  To add elements
    res.pop_back();
    subSequences(vec, res, ind + 1); // Not to take last element
}
int main()
{
    vector<int> vec = {3 ,1, 2};
    vector<int> res;
    subSequences(vec, res, 0);
    return 0;
}