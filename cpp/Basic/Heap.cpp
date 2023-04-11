#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(3);
    minheap.push(5);
    minheap.push(7);
    minheap.push(1);

    int min = minheap.top();
    minheap.pop();
    cout << min << "," << minheap.top() << endl;

    priority_queue<int, vector<int>, less<int>> maxheap;
    //priority_queue<int> maxheap; //default is maxheap

    maxheap.push(3);
    maxheap.push(5);
    maxheap.push(7);
    maxheap.push(1);

    int max = maxheap.top();
    maxheap.pop();
    cout << max << "," << maxheap.top() << endl;


    vector<int> arr = {4,2,6,8,2,4,0,3,9,6,7};
    priority_queue<int, vector<int>, greater<int>> heap(greater<int>(), arr);

    cout << heap.top() << endl;
    heap.pop();
    cout << heap.top() << endl;
    heap.pop();

    return 0;
}
