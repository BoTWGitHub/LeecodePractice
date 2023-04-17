#include <vector>
#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode* head){
    if(!head) return;
    while(head){
        cout << "[" << head->val << "]->";
        head = head->next;
    }
    cout << "\b\b" << endl;
}

ListNode* constructListByArray(vector<int> arr){
    ListNode* root = new ListNode();
    ListNode* cur = root;
    for(int num : arr){
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return root->next;
}
