#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public :
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = nullptr;
    }
    ListNode (int val) {
        val = val;
        next = nullptr;
    }
};

ListNode* addOneToLinkedList(ListNode* head) {
    ListNode* temp = head;
    vector<int> nums;
    while (temp) {
        nums.push_back(temp->val);
        temp = temp->next;
    }
    int carry = 1;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
        int sum = nums[i] + carry;
        nums[i] = sum % 10;
        carry = sum / 10;
    }

    ListNode* newHead = NULL;
    if (carry > 0) {
        newHead = new ListNode(carry);
        cout << carry;
        newHead->next = head;
    }
    else {
        newHead = head;
    }

    temp = head;
    for (int i = 0; i < n; i++) {
        temp->val = nums[i];
        cout << nums[i];
        temp = temp->next;
    }
    return newHead;
}
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);
    head->next->next->next = new ListNode(9);
    ListNode* newHead = addOneToLinkedList(head);
    return 0;
}