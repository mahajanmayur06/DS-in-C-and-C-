#include <iostream>
#include<bits/stdc++.h>

class ListNode {
public :
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode (int val) {
        val = val;
        next = NULL;
    }
};

void createCLL (ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    ListNode* temp = head;
    while (temp->val <= val && temp->next->val < val) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
int main() {
    return 0;
}