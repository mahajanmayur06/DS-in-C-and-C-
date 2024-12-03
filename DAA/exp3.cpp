#include <iostream>
#include <vector>
using namespace std;
int count = 0;

vector<int> mergeSort(int start, int end, vector<int> &v)
{
    if (end - start == 0)
    {
        vector<int> k = {v[start]};
        return k;
    }
    else if (end - start == 1)
    {
        if (v[start] > v[end])
        {
            int temp = v[start];
            v[start] = v[end];
            v[end] = temp;
            count++;
        }
        vector<int> k = {v[start], v[end]};
        return k;
    }
    int mid = (start + end) / 2;
    vector<int> v1 = mergeSort(start, mid, v);
    vector<int> v2 = mergeSort(mid + 1, end, v);
    vector<int> v3;
    int i1 = 0;
    int i2 = 0;
    while (i1 < v1.size() && i2 < v2.size())
    {
        if (v1[i1] <= v2[i2])
        {
            v3.push_back(v1[i1]);
            i1++;
        }
        else
        {
            v3.push_back(v2[i2]);
            count = count + (v1.size() - i1);
            i2++;
        }
    }
    while (i1 < v1.size())
    {
        v3.push_back(v1[i1]);
        i1++;
    }
    while (i2 < v2.size())
    {
        v3.push_back(v2[i2]);
        i2++;
    }
    return v3;
}
int main()
{
    vector<int> v;
    cout << "Enter elements of array, Enter -1 to exit" << endl;
    int k;
    while (true)
    {
        cin >> k;
        if (k == -1)
            break;
        v.push_back(k);
    }
    vector<int> useless = mergeSort(0, v.size() - 1, v);
    if (count == 0){
        cout << "Array element are already placed at right position";
        return 0;
    }
    cout << "\nThe array is not correctly sorted by " << count << " pairs"
         << endl;
    return 0;
}