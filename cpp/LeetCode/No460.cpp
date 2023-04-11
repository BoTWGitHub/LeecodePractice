/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

 - LFUCache(int capacity) Initializes the object with the capacity of the data structure.

 - int get(int key) Gets the value of the key if the key exists in the cache. 
   Otherwise, returns -1.

 - void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
   When the cache reaches its capacity, it should invalidate and remove the least frequently used key 
   before inserting a new item. 
   For this problem, when there is a tie (i.e., two or more keys with the same frequency)
   , the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. 
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        leastFreq = 1;
    }
    
    int get(int key) {
        if(mem.count(key)==0) return -1;
        
        increaseFreq(key);
        return mem[key].first;
    }
    
    void put(int key, int value) {
        if(mem.count(key)){ //update value and count
            increaseFreq(key);
            mem[key].first = value;
        }
        else{
            if(cap>0){ //insert new key
                cap--;
                leastFreq = 1;
                mem[key] = {value, 1};
                freq[1].push(key);
            }
            else{ //erase least freq
                eraseLeastFreq();
                leastFreq = 1;
                mem[key] = {value, 1};
                freq[1].push(key);
            }
        }
    }

    void increaseFreq(int key){
        int count = mem[key].second;
        if(freq[count].front()==key){
            freq[count].pop();
        }
        if(freq[count].empty()){
            if(leastFreq==count) leastFreq++;
            freq.erase(count);
        }
        count++;
        freq[count].push(key);
        mem[key].second++;
    }

    void eraseLeastFreq(){
        int eraseKey = freq[leastFreq].front();
        while(leastFreq!=mem[eraseKey].second){
            freq[leastFreq].pop();
            while(freq[leastFreq].empty()){
                freq.erase(leastFreq);
                leastFreq++;
            }
            eraseKey = freq[leastFreq].front();
        }
        freq[leastFreq].pop();
        if(freq[leastFreq].empty()) freq.erase(leastFreq);
        mem.erase(eraseKey);
    }
private:
    int cap;
    int leastFreq;
    unordered_map<int, pair<int, int>> mem; //key: val, count
    unordered_map<int, queue<int>> freq; //count: key
};

int main(void){
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl;
    lfu.put(3, 3);
    cout << lfu.get(2) << endl;
    cout << lfu.get(3) << endl;
    lfu.put(4, 4);
    cout << lfu.get(1) << endl;
    cout << lfu.get(3) << endl;
    cout << lfu.get(4) << endl;
    return 0;
}