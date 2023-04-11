/*
Given an array arr
, replace every element in that array with the greatest element among the elements to its right
, and replace the last element with -1.

After doing so, return the array.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int index = arr.size()-2;
        int temp_max = arr[arr.size()-1];
        arr[arr.size()-1] = -1;
        while(index>-1){
            if(arr[index] > temp_max){
                int temp2 = arr[index];
                arr[index] = temp_max;
                temp_max = temp2;
            }
            else{
                arr[index] = temp_max;
            }
            index--;
        }
        return arr;
    }
};

int main(void){
    vector<int> arr = {17,18,5,4,6,1};
    Solution solution;
    solution.replaceElements(arr);

    for(int num : arr){
        cout << num << ",";
    }
    cout << endl;

    return 0;
}