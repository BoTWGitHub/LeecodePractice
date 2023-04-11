/*
You are given an array nums consisting of positive integers and an integer k.

Partition the array into two ordered groups such that each element is in exactly one group. 
A partition is called great if the sum of elements of each group is greater than or equal to k.

Return the number of distinct great partitions. 
Since the answer may be too large, return it modulo 10^9 + 7.

Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long long s = 0;
        for(int num : nums) s+=num;
        if(s<k*2) return 0;
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(k+1, -1));
        int temp = (dp(nums, k, 0, mem)*2)%mod;
        int res = 1;
        for(int i=0;i<n;i++) res = (res*2)%mod;
        return (res-temp+mod)%mod;
    }
private:
    const int mod = 1e9+7;
    int dp(vector<int>& nums, int k, int index, vector<vector<int>>& mem){
        if(k<=0) return 0;
        if(index==nums.size()) return 1;
        if(mem[index][k]!=-1) return mem[index][k];

        int res = 0;
        res = (res + (dp(nums, k-nums[index], index+1, mem) + dp(nums, k, index+1, mem)))%mod;
        return mem[index][k] = res;
    }
};

int main(void){
    Solution solution;
    vector<int> nums;
    int k;

    nums = {1,2,3,4};
    k = 4;
    cout << solution.countPartitions(nums, k) << endl;

    nums = {3,3,3};
    k = 4;
    cout << solution.countPartitions(nums, k) << endl;

    nums = {6,6};
    k = 2;
    cout << solution.countPartitions(nums, k) << endl;

    nums = {96,40,22,98,9,97,45,22,79,57,95,62};
    k = 505;
    cout << solution.countPartitions(nums, k) << endl;

    nums = {367,160,643,105,915,595,517,327,57,638,609,181,595,341,901,365,990,55,496,232,840,825,19,482,910,109,926,169,1,325,252,593,11,583,239,840,928,423,620,829,706,313,445,135,981,285,780,5,678,117,376,494,383,681,244,989,780,493,697,203,810,833,138,555,411,109,832,504,325,758,404,323,709,831,311,870,360,322,866,10,959,543,54,715,638,804,263,663,441,702,473,309,279,143,924,298,712,80,122,863,880,289,682,517,471,4,985,743,501,157,381,22,914,293,332,8,604,410,519,889,162,722,676,601,910,54,536,220,89,501,411,754,409,527,714,395,915,338,442,822,70,839,15,451,937,47,88,988,608,357,385,952,766,917,543,810,217,47,717,306,201,91,93,135,418,56,519,269,855,755,98,735,414,742,552,885,183,694,463,292,318,239,459,763,698,447,506,657,108,185,666,697,849,782,461,285,950,704,951,846,86,600,429,111,520,14,576,591,602,678,961,2,766,710,643,385,465,66,748,528,758,1,54,969,635,588,625,44,927,921,9,50,632,77,735,977,521,64,282,362,996,561,125,319,556,209,855,280,613,432,93,126,427,780,969,933,809,637,294,225,367,351,290,406,35,460,153,625,695,77,389,279,648,804,65,624,405,428,49,851,515,449,340,43,708,405,201,283,779,201,306,707,372,15,971,566,828,819,537,747,730,764,141,248,768,195,986,834,775,719,969,23,866,724,780,24,744,727,53,414,100,246,506,364,315,142,516,66,947,669,272,753,621,169,73,169,930,345,767,555,82,806,312,552,57,432,759,942,339,385,242,297,120,785,443,843,642,224,873,556,278,855,273,803,597,288,478,300,894,462,354,901,366,489,664,551,758,727,528,276,228,890,602,768,752,577,586,92,97,956,688,438,501,372,20,352,308,923,545};
    k = 787;
    cout << solution.countPartitions(nums, k) << endl;
    return 0;
}