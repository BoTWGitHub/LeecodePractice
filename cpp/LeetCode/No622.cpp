/*
Design your implementation of the circular queue.
The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle 
and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
In a normal queue, once the queue becomes full, 
we cannot insert the next element even if there is a space in front of the queue. 
But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. 
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v){
    cout << "[";
    for(int num : v){
        cout << num << ", ";
    }
    cout << "]" << endl;
}

class MyCircularQueue {
public:
    vector<int> nums;
    int head = -1;
    int tail = -1;
    MyCircularQueue(int k) {
        nums = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(this->isEmpty()){
            head = 0;
            tail = 0;
            nums[head] = value;
            return true;
        }
        else if(this->isFull()){
            return false;
        }
        else{
            tail = (tail+1)%(nums.size());
            nums[tail] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(this->isEmpty()){
            return false;
        }
        else if(head == tail){
            head = -1;
            tail = -1;
            return true;
        }
        else{
            head = (head+1)%(nums.size());
            return true;
        }
    }
    
    int Front() {
        if(this->isEmpty()){
            return -1;
        }
        else{
            return nums[head];
        }
    }
    
    int Rear() {
        if(this->isEmpty()){
            return -1;
        }
        else{
            return nums[tail];
        }
    }
    
    bool isEmpty() {
        if(head == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((tail+1)%(nums.size())==head){
            return true;
        }
        return false;
    }
};

int main(void){
    MyCircularQueue mCQ(3);
    cout << mCQ.enQueue(1) << endl;
    cout << mCQ.enQueue(2) << endl;
    cout << mCQ.enQueue(3) << endl;
    cout << mCQ.enQueue(4) << endl;
    cout << mCQ.Rear() << endl;
    cout << mCQ.isFull() << endl;
    cout << mCQ.deQueue() << endl;
    cout << mCQ.enQueue(4) << endl;
    cout << mCQ.Rear() << endl;
    return 0;
}