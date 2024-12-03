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

void insertAtBeg(Node*& head, int val) {
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = head;
    head = new_node;    
}

// 1 2 3 4 5 N
void insertAtEnd(Node* head, int val) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* new_node = new Node(val);
    temp->next = new_node;
}

// 1 2 3 5 6 N ...4
void insertAfter(Node* head, int x, int val) {
    Node* temp = head;
    while (temp->data != x) {
        temp = temp->next;
    }
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
}

void removeHead(Node* head) {
    if (head == NULL) {
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
void removeTail(Node* head) {
    Node *temp = head;
    if (head == NULL || head->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

void removeN(Node* head, int n) {
    Node* temp = head;
    if (head == NULL || head->next == NULL) {
        head = NULL;
        return;
    }
    Node* prev = head;
    while (temp != NULL) {
        if (temp->data == n) {
            prev->next = prev->next->next;
            free(temp);
            free(prev);
        }
        prev = temp;
        temp = temp->next;
    }

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
    Node* head = new Node(4);
    insertAtBeg(head, 2);
    insertAtEnd(head, 6);
    insertAtEnd(head, 8);
    insertAfter(head, 4, 5);
    removeN(head, 6);
    printLL(head);
    return 0;
}