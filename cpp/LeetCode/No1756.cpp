/*
Design a queue-like data structure that moves the most recently used element to the end of the queue.

Implement the MRUQueue class:

MRUQueue(int n) constructs the MRUQueue with n elements: [1,2,3,...,n].
int fetch(int k) moves the kth element (1-indexed) to the end of the queue and returns it.
*/
#include <iostream>
#include <deque>
#include <stack>
#include "Debug\VectorDebug.h"
using namespace std;

class MRUQueue {
public:
    MRUQueue(int n) {
        this->n = n;
        for(int i=1;i<n+1;i++) q.push_back(i);
    }
    
    int fetch(int k) {
        int res;
        if(n-k<k-1){
            for(int i=0;i<n-k;i++){
                sk.push(q.back());
                q.pop_back();
            }
            res = q.back();
            q.pop_back();
            while(!sk.empty()){
                q.push_back(sk.top());
                sk.pop();
            }
        }
        else{
            for(int i=0;i<k-1;i++){
                sk.push(q.front());
                q.pop_front();
            }
            res = q.front();
            q.pop_front();
            while(!sk.empty()){
                q.push_front(sk.top());
                sk.pop();
            }
        }
        q.push_back(res);
        return res;
    }
private:
    int n;
    deque<int> q;
    stack<int> sk;
};

int main(void){
    MRUQueue mru(8);
    cout << mru.fetch(3) << endl;
    cout << mru.fetch(5) << endl;
    cout << mru.fetch(2) << endl;
    cout << mru.fetch(8) << endl;
    return 0;
}