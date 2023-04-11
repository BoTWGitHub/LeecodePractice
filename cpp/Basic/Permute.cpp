#include <iostream>
#include <vector>
#include <set>

using namespace std;

void permutation(vector<int> arr, vector<vector<int>> &res, int step=0){
    if(step==arr.size()){
        res.push_back(arr);
        return;
    }

    for(int i=step;i<arr.size();i++){
        swap(arr[i], arr[step]);
        permutation(arr, res, step+1);
        swap(arr[i], arr[step]);
    }
}

void printVector(vector<int> arr){
    cout << "[ ";
    for(int num : arr){
        cout << num << ",";
    }
    cout << " ]" << endl;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;
    permutation(arr, result);

    cout << "Original Array: ";
    printVector(arr);

    cout << "Permute Array: " << endl;
    for(vector<int> v : result){
        printVector(v);
    }

    return 0;
}
