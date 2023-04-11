#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mem;
        for(int i=0;i<nums.size();i++){
            int temp = target - nums[i];
            if(mem.find(temp) != mem.end()){
                return vector<int>({mem[temp], i});
            }
            mem[nums[i]] = i;
        }
        return vector<int>({-1});
    }
};

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;

    Solution solution;
    vector<int> res = solution.twoSum(nums, target);

    for(int num : res){
        printf("%d, ", num);
    }
    printf("\r\n");

    return 0;
}
