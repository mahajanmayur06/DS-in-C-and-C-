#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Heap {
    int size;
    int arr[100];

public:
    Heap() {
        arr[0] = -1; 
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int i = size;
        arr[i] = val;

        while (i > 1) {
            int parent = i / 2;
            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;  
            } 
            else {
                return;
            }
        }
    }

    void deleteTop() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        
        arr[1] = arr[size];
        size--;
        int i = 1;

        while (i <= size) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest]) {
                largest = right;
            }
            else {
                return;
            }
        }
    }

    void printHeap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(vector<int>& arr, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    int n = arr.size();
    if (left <= n && arr[largest ] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != i) {
        swap (arr[largest], arr[i]);
        heapify(arr, largest);
    }
}

int main() {
    Heap h;
    h.insert(50);
    h.insert(60);
    h.insert(10);
    h.insert(90);
    h.insert(70);
    h.insert(20);

    h.printHeap();

    h.deleteTop();
    h.printHeap();

    return 0;
}
