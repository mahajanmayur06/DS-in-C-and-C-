#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    int k;
    cout << "Input a array element or exit with -1" << endl;
    while (true)
    {
        cin >> k;
        if (k == -1)
            break;
        arr.push_back(k);
    }

    cout << "Enter the number you want to search ";
    cin >> k;

    int flag = 0;
    int l = arr.size() - 1;
    int f = 0;
    int m;
    while (1)
    {
        if (arr[f] == k)
        {
            m = f;
            break;
        }
        if (arr[l] == k)
        {
            m = l;
            break;
        }

        m = (f + l) / 2;
        if (arr[m] == k)
            break;

        if (f == m || m == l)
        {
            flag = 1;
            break;
        }

        if (arr[f] < arr[m])
        {
            if (arr[f] < k && k < arr[m])
                l = m;

            else
                f = m;
        }
        else if (arr[m] < arr[l])
        {
            if (arr[m] < k && k < arr[l])
                f = m;

            else
                l = m;
        }
    }

    if (flag == 1)
        cout << "Not Found" << endl;
    else
        cout << "Element " << arr[m] << " found at Index " << m;

    return 0;
}
