/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/
#include <iostream>
#include <vector>
#include "Debug\ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> temp;
        ListNode* cur = head;
        for(int i=0;i<k;i++){
            if(cur){
                temp.push_back(cur);
                cur = cur->next;
            }
            else{
                return head;
            }
        }
        temp[0]->next = temp.back()->next;
        for(int i=1;i<k;i++){
            temp[i]->next = temp[i-1];
        }
        head = temp.back();
        temp[0]->next = reverseKGroup(temp[0]->next, k);
        return head;
    }
};

int main(void){
    Solution solution;
    ListNode* head;
    int k;

    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    k = 2;
    head = solution.reverseKGroup(head, k);
    printListNode(head);

    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    k = 3;
    head = solution.reverseKGroup(head, k);
    printListNode(head);
    return 0;
}