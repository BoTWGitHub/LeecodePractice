/*
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        infinite = 1;
    }
    
    int popSmallest() {
        int res = -1;
        if(!minHeap.empty()){
            res = minHeap.top();
            minHeap.pop();
            numPool.erase(res);
        }
        else{
            res = infinite++;
        }
        return res;
    }
    
    void addBack(int num) {
        if(num<infinite && numPool.count(num)==0){
            minHeap.push(num);
            numPool.insert(num);
        }
    }
private:
    int infinite;
    std::priority_queue<int
            , std::vector<int>
            , std::greater<int>> minHeap;
    std::unordered_set<int> numPool;
};

int main(void){
    SmallestInfiniteSet si;
    si.addBack(2);
    std::cout << si.popSmallest() << std::endl;
    std::cout << si.popSmallest() << std::endl;
    std::cout << si.popSmallest() << std::endl;
    si.addBack(1);
    si.addBack(1);
    std::cout << si.popSmallest() << std::endl;
    std::cout << si.popSmallest() << std::endl;
    std::cout << si.popSmallest() << std::endl;
    return 0;
}