#include <iostream>
using namespace std;

bool chkRotationKMP(string s1, string s2)
{

    if (s1.length() != s2.length())
        return false;

    string txt = s1 + s1;

    int n = txt.length();
    int m = s2.length();

    int lps[m];
    int l = 0, k = 1;

    while (k < m)
    {
        if (s2[k] == s2[l])
        {
            l++;
            lps[k] = 1;
            k++;
        }

        else
        {
            if (l != 0)
                l = lps[l - 1];
            else
            {
                lps[k] = 0;
                k++;
            }
        }
    }

    int i = 0, j = 0;

    while (i < n)
    {
        if (s2[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
            cout << "found at " << i << endl;
        else if (i < n && s2[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}

int main()
{
    string a = "car", b = "arc";
    if (chkRotationKMP(a, b))
        cout << "Given strings are rotations of each other.";
    else
        cout << "Given strings are not rotations of each other.";
    return 0;
}