/*
Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.
*/
#include <iostream>
#include <utility>
#include <map>
#include <vector>

using namespace std;

class DoubleLinkedList{
public:
    int val;
    DoubleLinkedList* next;
    DoubleLinkedList* prev;
    DoubleLinkedList(int v) : val(v), next(nullptr), prev(nullptr){};
    DoubleLinkedList(int v, DoubleLinkedList* n, DoubleLinkedList* p) : val(v), next(n), prev(p){};
};

class MaxStack {
public:
    MaxStack() {
        start = new DoubleLinkedList(0);
        end = new DoubleLinkedList(0, nullptr, start);
        start->next = end;
    }
    
    void push(int x) {
        insertNewNode(x);
    }
    
    int pop() {
        DoubleLinkedList* node = end->prev;
        removeNode(node);
        return node->val;
    }
    
    int top() {
        return end->prev->val;
    }
    
    int peekMax() {
        return searchMax();
    }
    
    int popMax() {
        int maxNum = searchMax();
        DoubleLinkedList* node = mem[maxNum].back();
        mem[maxNum].pop_back();
        if(mem[maxNum].empty()) mem.erase(maxNum);
        removeNode(node);
        return node->val;
    }
private:
    DoubleLinkedList* start;
    DoubleLinkedList* end;
    map<int, vector<DoubleLinkedList*>> mem;
    void insertNewNode(int x){
        DoubleLinkedList* node = new DoubleLinkedList(x, end, end->prev);
        end->prev->next = node;
        end->prev = node;
        mem[x].push_back(node);
    }
    void removeNode(DoubleLinkedList* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }
    int searchMax(){
        int maxNum = mem.rbegin()->first;
        DoubleLinkedList* node = mem[maxNum].back();
        while(!node->next){
            mem[maxNum].pop_back();
            if(mem[maxNum].empty()){
                mem.erase(maxNum);
                maxNum = mem.rbegin()->first;
                node = mem[maxNum].back();
            }
            else{
                node = mem[maxNum].back();
            }
        }
        return node->val;
    }
};

int main(){
    MaxStack m;
    m.push(5);
    m.push(1);
    m.push(6);
    cout << m.peekMax() << endl;
    cout << m.popMax() << endl;
    cout << m.popMax() << endl;
    cout << m.top() << endl;
    return 0;
}
