/*
Design the CombinationIterator class:

CombinationIterator(string characters, int combinationLength) Initializes the object 
with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.

next() Returns the next combination of length combinationLength in lexicographical order.

hasNext() Returns true if and only if there exists a next combination.
*/
#include <iostream>
#include <vector>
using namespace std;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        index = vector<int>(combinationLength);
        for(int i=0;i<index.size();i++){
            index[i] = i;
        }
    }
    
    string next() {
        string res;
        for(int i : index){
            res.push_back(characters[i]);
        }
        index.back()++;
        if(index.back()==characters.size()){
            int j = index.size()-2;
            while(j>=0 && ++index[j]==index[j+1]-1){
                j--;
            }
            if(j>=0){
                for(int i=j+1;i<index.size();i++){
                    index[i] = index[i-1]+1;
                }
            }
        }
        return res;
    }
    
    bool hasNext() {
        return index[0]!=(characters.size()-index.size()+1);
    }
private:
    string characters;
    vector<int> index;
};


int main(void){
    string characters;
    int combinationLength;
    characters = "abcdefg";
    combinationLength = 3;
    CombinationIterator ci(characters, combinationLength);
    while(ci.hasNext()){
        cout << ci.next() << endl;
    }
    return 0;
}