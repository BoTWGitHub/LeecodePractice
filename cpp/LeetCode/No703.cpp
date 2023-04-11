/*
Design a class to find the kth largest element in a stream. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
*/
#include <iostream>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        min_heap = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        while(min_heap.size()>size){
            min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        while(min_heap.size()>size){
            min_heap.pop();
        }
        return min_heap.top();
    }
private:
    int size;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};


int main(){
    vector<int> nums = {4,5,8,2};
    KthLargest k(3, nums);
    
    cout << k.add(3) << endl;
    cout << k.add(5) << endl;
    cout << k.add(10) << endl;
    cout << k.add(9) << endl;
    cout << k.add(4) << endl;
    return 0;
}
