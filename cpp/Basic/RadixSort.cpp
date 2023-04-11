#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector<int> nums = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    int maxNum = *max_element(nums.begin(), nums.end());
    int divider = 1;
    while(maxNum/divider){
        vector<int> count(10, 0);
        for(int num : nums){
            count[num/divider%10]++;
        }
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        vector<int> temp(nums.size(), 0);
        for(int i=nums.size()-1;i>-1;i--){ //this reverse order matters!!
            temp[--count[nums[i]/divider%10]] = nums[i];
        }
        nums = temp;
        divider*=10;
    }

    for(int num : nums){
        cout << num << ",";
    }
    cout << endl;

    return 0;
}