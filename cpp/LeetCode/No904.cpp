/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. 
The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. 
However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.

Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. 
The picked fruits must fit in one of your baskets.

Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        std::unordered_map<int, int> buckets;
        int left = 0, right = 0;

        for(right=0;right<fruits.size();right++){
            buckets[fruits[right]]++;
            if(buckets.size()>2){
                buckets[fruits[left]]--;
                if(buckets[fruits[left]]==0){
                    buckets.erase(fruits[left]);
                }
                left++;
            }
        }
        return right-left;
    }
};

int main(void){
    Solution solution;
    std::vector<int> fruits;

    fruits = {1,2,1};
    std::cout << solution.totalFruit(fruits) << std::endl;

    fruits = {0,1,2,2};
    std::cout << solution.totalFruit(fruits) << std::endl;

    fruits = {1,2,3,2,2};
    std::cout << solution.totalFruit(fruits) << std::endl;

    fruits = {1,2,2,1,1,2,3,2,2};
    std::cout << solution.totalFruit(fruits) << std::endl;
    return 0;
}