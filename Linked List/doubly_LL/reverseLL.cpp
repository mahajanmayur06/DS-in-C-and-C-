#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node {
public :
    int data;
    Node* next;
    Node* prev;
    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node (int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* push_back(Node* head, int val) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    newNode->prev = temp;
    temp->next = newNode;
    return head;
}
Node* reverse(Node* head){
    if (head == NULL || head->next == NULL) return head;
    Node* curr = head;
    Node* last = NULL;
    while (curr != NULL) {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }
    return last->prev;
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
    Node* head = new Node(10);
    head = push_back(head, 20);
    head = push_back(head, 30);
    head = push_back(head, 40);
    head = push_back(head, 50);
    head = push_back(head, 60);
    printLL(head);
    head = reverse(head);
    printLL(head);
    return 0;
}