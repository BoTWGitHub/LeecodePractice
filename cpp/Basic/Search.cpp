#include <iostream>
#include <vector>

using namespace std;

class Search{
public:
    int linearSearch(vector<int> &nums, int target){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
    int binarySearch(vector<int> &nums, int target){
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return -1;
    }
};

int main(void){
    Search search;

    vector<int> nums{1,3,5,7,9,13,15,17};
    int target = 7;
    cout << search.binarySearch(nums, target) << endl;

    return 0;
}