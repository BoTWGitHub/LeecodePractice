#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T>& v){
    if(v.size()==0){
        cout << "[]" << endl;
        return;
    }
    cout << "[ ";
    for(T n : v){
        cout << n << ", ";
    }
    cout << "\b\b]" << endl;
}

template <typename T>
void print2DVector(const vector<vector<T>>& v){
    if(v.size()==0){
        cout << "[]" << endl;
        return;
    }
    cout << "[" << endl;
    for(vector<T> r : v){
        cout << "  [";
        for(T n : r){
            cout << n << ",";
        }
        cout << "\b]" << endl;
    }
    cout << "]" << endl;
}

template <typename T>
void refresh2DVector(const vector<vector<T>>& v){
    system("CLS");
    print2DVector(v);
}