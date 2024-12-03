#include <iostream>
#include <vector>
using namespace std;

bool flag = false;

void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int>& subset)
{
	if (targetSum == 0) {
		flag = true;
		cout << "[ ";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i] << " ";
		}
		cout << "]" << endl;
		return;
	}

	if (i == n) {
		return;
	}

	PrintSubsetSum(i + 1, n, set, targetSum, subset);
	if (set[i] <= targetSum) {
		subset.push_back(set[i]);
		PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);
		subset.pop_back();
	}
}

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int set[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> set[i];
	}

	int sum;
	cout << "Enter the target sum: ";
	cin >> sum;

	vector<int> subset;
	PrintSubsetSum(0, n, set, sum, subset);

	if (!flag) {
		cout << "There is no such subset";
	}

	return 0;
}
