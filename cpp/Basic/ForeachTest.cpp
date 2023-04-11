#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int arr[5] = {1,2,3,4,5};
    vector<int> vec = {5,4,3,2,1};

    cout << endl;
    for(int num : arr){
        cout << num << ",";
    }

    cout << endl;
    for(int num : vec){
        cout << num << ",";
    }
}