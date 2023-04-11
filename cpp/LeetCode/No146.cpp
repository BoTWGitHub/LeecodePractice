/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

struct DoubleList{
    int key;
    int val;
    DoubleList* next = nullptr;
    DoubleList* prev = nullptr;
    DoubleList() : key(0), val(0) {}
    DoubleList(int k, int v) : key(k), val(v) {}
    DoubleList(int k, int v, DoubleList* n, DoubleList* p) : key(k), val(v), next(n), prev(p) {}
    void printDoubleList(){
        DoubleList* cur = this;
        while(cur){
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.count(key)==0){
            return -1;
        }
        else{
            moveToFront(key);
            return map[key]->val;
        }
    }
    
    void put(int key, int value) {
        checkKey(key, value);
    }

private:
    int cap;
    int size = 0;
    DoubleList* head = new DoubleList();
    DoubleList* tail = new DoubleList();
    unordered_map<int, DoubleList*> map;
    void checkKey(int key, int value){
        if(map.count(key)>0){
            map[key]->val = value;
            moveToFront(key);
        }
        else{
            insertNew(key, value);
        }
    }
    void insertNew(int key, int value){
        size++;
        DoubleList* node = new DoubleList(key, value, head->next, head);
        map[key] = node;
        head->next->prev = node;
        head->next = node;
        if(size>cap){
            removeLast();
        }
    }
    void removeLast(){
        DoubleList* node = tail->prev;
        map.erase(node->key);
        size--;
        node->prev->next = tail;
        tail->prev = node->prev;
        delete(node);
    }
    void moveToFront(int key){
        DoubleList* node = map[key];
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
};

int main(){
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;

    return 0;
}
