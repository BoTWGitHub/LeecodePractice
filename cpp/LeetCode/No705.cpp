/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

#include <iostream>

using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        for(int i=0;i<1000;i++){
            buckets[i] = nullptr;
        }
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        int index = hash_function(key);
        if(!buckets[index]){
            buckets[index] = new ListNode(key);
        }
        else{
            ListNode *node = buckets[index];
            while(node->next){
                node = node->next;
            }
            node->next = new ListNode(key);
        }
    }
    
    void remove(int key) {
        if(!contains(key)){
            return;
        }
        int index = hash_function(key);
        if(buckets[index]->val == key){
            if(buckets[index]->next){
                buckets[index] = buckets[index]->next;
            }
            else{
                buckets[index] = nullptr;
            }
        }
        else{
            ListNode *node = buckets[index];
            while(node->next->val != key){
                node = node->next;
            }
            node->next = node->next->next;
        }
    }
    
    bool contains(int key) {
        int index = hash_function(key);
        if(!buckets[index]){
            return false;
        }
        else{
            ListNode *node = buckets[index];
            while(node){
                if(node->val == key){
                    return true;
                }
                node = node->next;
            }
        }
        return false;
    }
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode() : val(-1), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr){}
    };

    int hash_function(int key){
        return key%1000;
    }

    ListNode* buckets[1000];
};

int main(){
    MyHashSet set;
    cout << set.contains(2) << endl;

    cout << "add 2" << endl;
    set.add(2);
    cout << "add 2" << endl;
    set.add(2);

    cout << set.contains(2) << endl;

    cout << "remove 2" << endl;
    set.remove(2);

    cout << set.contains(2) << endl;

    return 0;
}
