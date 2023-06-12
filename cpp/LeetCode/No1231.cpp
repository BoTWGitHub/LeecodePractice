/*
You have one chocolate bar that consists of some chunks. 
Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 pieces using k cuts
, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    int maximizeSweetness(std::vector<int>& sweetness, int k) {
        int left = INT_MAX, right = 0;
        for(int sweet : sweetness){
            left = std::min(left, sweet);
            right+=sweet;
        }
        while(left<right){
            int mid = (right-left+1)/2+left;
            int cut = 0;
            int tempSum = 0;
            for(int sweet : sweetness){
                tempSum+=sweet;
                if(tempSum>=mid){
                    tempSum = 0;
                    cut++;
                }
            }
            if(cut<=k) right = mid-1;
            else left = mid;
        }
        return left;
    }
};

int main(void){
    Solution solution;
    std::vector<int> sweetness;
    int k;

    sweetness = {1,2,3,4,5,6,7,8,9};
    k = 5;
    std::cout << solution.maximizeSweetness(sweetness, k) << std::endl;

    sweetness = {5,6,7,8,9,1,2,3,4};
    k = 8;
    std::cout << solution.maximizeSweetness(sweetness, k) << std::endl;

    sweetness = {1,2,2,1,2,2,1,2,2};
    k = 2;
    std::cout << solution.maximizeSweetness(sweetness, k) << std::endl;
    return 0;
}