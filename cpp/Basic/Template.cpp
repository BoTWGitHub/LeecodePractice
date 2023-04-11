#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

template <typename T>
void printVector(const vector<T>& v){
    cout << "[";
    for(T n : v){
        cout << n << ",";
    }
    cout << "\b]" << endl;
}

int main(){
    cout << minimum<int>(5, 3) << endl;

    vector<int> v1{2,3,5,8,4};
    printVector<int>(v1);

    vector<string> v2{"abc", "ase", "xcv"};
    printVector<string>(v2);

    vector<char> v3{'a', 'd', 'e', 'v'};
    printVector<char>(v3);

    return 0;
}
