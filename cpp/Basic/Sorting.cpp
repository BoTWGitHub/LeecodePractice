#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
    cout << "[";
    for(int num : v){
        cout << num << ", ";
    }
    cout << "]" << endl;
}

class Sorting{
public:
    vector<int> mergeSort(vector<int> nums){
        if(nums.size()<=1){
            return nums;
        }

        int mid = nums.size()/2;
        vector<int> left = mergeSort(vector<int>{nums.begin(), nums.begin()+mid});
        vector<int> right = mergeSort(vector<int>{nums.begin()+mid, nums.end()});

        vector<int> result;
        vector<int>::iterator it1 = left.begin(), it2 = right.begin();
        
        while(it1<left.end() && it2<right.end()){
            if(*it1<*it2){
                result.push_back(*it1);
                it1++;
            }
            else{
                result.push_back(*it2);
                it2++;
            }
        }
        while(it1<left.end()){
            result.push_back(*it1);
            it1++;
        }
        
        while(it2<right.end()){
            result.push_back(*it2);
            it2++;
        }
        return result;
    }
    
    vector<int> quickSort(vector<int> nums){
        qs(nums, &nums.front(), &nums.back());
        return nums;
    }
    void qs(vector<int> &nums, int *left, int *right){
        if(left>=right){
            return;
        }
        int *rand = (right-left)/2 + left;
        swap(*rand, *right);
        int *index = left;
        for(int *num=left;num<right;num++){
            if(*num<*right){
                swap(*num, *index);
                index++;
            }
        }
        swap(*right, *index);
        qs(nums, left, index-1);
        qs(nums, index+1, right);
    }
};

int main(void){
    Sorting sort;

    vector<int> nums{3,5,7,2,8,4,1,6};
    printVector(nums);
    vector<int> res = sort.quickSort(nums);
    printVector(res);
    return 0;
}
