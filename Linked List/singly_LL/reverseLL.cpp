#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public :
    int data;
    Node* next;
    Node() {
        data = 0;
        next = nullptr;
    }
    Node (int val) {
        data = val;
        next = nullptr;
    }
};

Node* reverseLL(Node* head, Node* prev) {
    if (head == NULL) {
        return prev;
    }

    Node* nextNode = head->next;
    head->next = prev;
    return reverseLL(nextNode, head);
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(10);
    Node* prev = NULL;
    head = reverseLL(head, prev);
    printLL(head);
    return 0;
}