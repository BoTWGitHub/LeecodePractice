#include <iostream>

using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {
    }
    
    int get(int index) {
        if(!_head){
            return -1;
        }
        int count = 0;
        ListNode *cur = _head;
        while(cur->next && count<index){
            cur = cur->next;
            count++;
        }
        if(count == index){
            return cur->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        if(!_head){
            _head = new ListNode(val);
        }
        else{
            ListNode *temp = _head;
            _head = new ListNode(val, temp);
        }
    }
    
    void addAtTail(int val) {
        if(!_head){
            _head = new ListNode(val);
        }
        else{
            ListNode *cur = _head;
            while(cur->next){
                cur = cur->next;
            }
            cur->next = new ListNode(val);
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        if(!_head){
            return;
        }
        int count = 0;
        ListNode *cur = _head;
        while(cur->next && count<index-1){
            cur=cur->next;
            count++;
        }
        if(count==index-1){
            ListNode *temp = new ListNode(val, cur->next);
            cur->next = temp;
        }
    }
    
    void deleteAtIndex(int index) {
        if(!_head){
            return;
        }
        if(index==0){
            _head = _head->next;
            return;
        }
        int count = 0;
        ListNode *cur = _head;
        while(cur->next && count<index-1){
            cur = cur->next;
            count++;
        }
        if(count==index-1 && cur->next){
            cur->next = cur->next->next;
        }
    }

    void printList(void){
        ListNode *cur = _head;
        cout << "===print list===" << endl;
        while(cur){
            cout << " " << cur->val << " ->";
            cur = cur->next;
        }
        cout << endl << "===print done===" << endl;
    }

private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode *_head = NULL;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(void){
    MyLinkedList list;
    list.printList();

    list.addAtHead(3);
    list.printList();

    list.addAtHead(4);
    list.printList();

    list.addAtTail(8);
    list.printList();

    cout << list.get(0) << list.get(1) << endl;

    return 0;
}