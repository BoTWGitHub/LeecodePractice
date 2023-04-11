#include <unordered_map>
#include <map>
#include <utility>

using namespace std;

template<typename T1, typename T2>
void printUnorderedMap(unordered_map<T1, T2> &m){
    for(pair<T1, T2> element : m){
        cout << element.first << ": " << element.second << endl;
    }
}

template<typename T1, typename T2>
void printMap(map<T1, T2> &m){
    for(pair<T1, T2> element : m){
        cout << element.first << ": " << element.second << endl;
    }
}