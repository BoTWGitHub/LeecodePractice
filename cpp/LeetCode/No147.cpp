/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
*/
#include <iostream>
#include "Debug\ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* last = head;
        while(cur){
            last->next = cur->next;
            if(cur->val<head->val){
                cur->next = head;
                head = cur;
                cur = last->next;
            }
            else{
                ListNode* temp = head;
                while(temp!=last && temp->next->val<cur->val){
                    temp = temp->next;
                }
                if(temp!=last){
                    cur->next = temp->next;
                    temp->next = cur;
                    cur = last->next;
                }
                else{
                    cur->next = temp->next;
                    temp->next = cur;
                    last = cur;
                    cur = cur->next;
                }
            }
        }
        return head;
    }
};

int main(void){
    Solution solution;
    ListNode* head;

    head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    head = solution.insertionSortList(head);
    printListNode(head);

    head = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));
    head = solution.insertionSortList(head);
    printListNode(head);

    return 0;
}