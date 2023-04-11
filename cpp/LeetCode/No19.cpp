/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/
#include <iostream>

using namespace std;

/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void printList(){
        ListNode* node = this;
        while(node){
            cout << node->val << " -> ";
            node = node->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(remover(head, n) == n) return head->next;
        return head;
    }
    int remover(ListNode* head, int n){
        if(!head) return 0;
        int h = remover(head->next, n);
        if(h==n){
            ListNode* node = head->next;
            head->next = node->next;
            delete(node);
        }
        return h+1;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head->printList();
    //ListNode* head = new ListNode(1, new ListNode(2));
    //head->printList();

    head = solution.removeNthFromEnd(head, 2);
    head->printList();

    return 0;
}
