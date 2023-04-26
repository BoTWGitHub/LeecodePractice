/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
*/
#include <iostream>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++){
            int target = c - i*i;
            int left = 0, right = target;
            while(left<=right){
                int mid = (right-left)/2+left;
                long long square = (long long)mid*mid;
                if(square==target) return true;
                else if(square>target) right = mid-1;
                else left = mid+1;
            }
        }
        return false;
    }
};

int main(void){
    Solution solution;
    int c;

    c = 5;
    std::cout << solution.judgeSquareSum(c) << std::endl;

    c = 3;
    std::cout << solution.judgeSquareSum(c) << std::endl;

    c = 4;
    std::cout << solution.judgeSquareSum(c) << std::endl;

    c = 0;
    std::cout << solution.judgeSquareSum(c) << std::endl;

    c = 100000;
    std::cout << solution.judgeSquareSum(c) << std::endl;

    c = 2^31-1;
    std::cout << solution.judgeSquareSum(c) << std::endl;
    return 0;
}