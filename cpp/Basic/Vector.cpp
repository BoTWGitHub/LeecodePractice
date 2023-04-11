#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v){
    cout << "[";
    for(int num : v){
        cout << num << ",";
    }
    cout << "]" << endl;
}

void printMatrix(vector<vector<int>> mat){
    cout << "[";
    for(vector<int> v : mat){
        cout << "[";
        for(int num : v){
            cout << num << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int sumTheVectorByIndex(int *left, int *right){
    int res = 0;
    for(int *num = left;num<=right;num++){
        res+=*num;
    }
    return res;
}

int main(void){
    vector<int> v;
    vector<int>::iterator it;
    vector<vector<int>> test;
    int temp;

    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    printVector(v);

    v.pop_back();
    it = v.end() - 1;
    cout << *it << endl;

    printVector(v);

    v.insert(v.begin(), 0);

    printVector(v);

    test.push_back(v);
    
    printMatrix(test);

    v.push_back(6);
    v.push_back(7);

    printVector(v);
    printMatrix(test);

    cout << v.front() << ", " << v.back() << ", " << sumTheVectorByIndex(&v.front(), &v.back()) << endl;

    vector<int> v2{v.begin(), v.begin()+2};
    printVector(v2);

    vector<int> v3(5);
    cout << v3.size() << ", " << v3.capacity() << endl;
    printVector(v3);

    return 0;
}