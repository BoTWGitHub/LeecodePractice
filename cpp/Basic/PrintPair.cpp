#include <iostream>

using namespace std;

void printPair(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
        }
    }
}

int main(void){
    int arr[] = {1,2,3,4};
    
    printPair(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}