/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. 
If there are multiple such values, it returns the value associated with the largest timestamp_prev. 
If there are no values, it returns "".
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.count(key)==0 || timestamp<store[key][0].first) return "";

        int left = 0, right = store[key].size()-1;
        while(left<right){
            int mid = (right-left)/2 + left + (right-left)%2;
            if(store[key][mid].first==timestamp) return store[key][mid].second;
            else if(store[key][mid].first>timestamp) right = mid-1;
            else left = mid;
        }
        if(left==0 && store[key][left].first>timestamp) return "";
        else return store[key][left].second;
    }
private:
    unordered_map<string, vector<pair<int, string>>> store;
};

int main(){
    TimeMap t;
    t.set("foo", "bar", 1);
    cout << t.get("foo", 1) << endl;
    cout << t.get("foo", 3) << endl;
    t.set("foo", "bar2", 4);
    cout << t.get("foo", 4) << endl;
    cout << t.get("foo", 5) << endl;
    return 0;
}
