#include "VectorDebug.h"

class UnionFind{
public:
    UnionFind(int size){
        root = vector<int>(size, 0);
        rank = vector<int>(size, 1);
        for(int i=0;i<size;i++) root[i] = i;
        numOfGroup = size;
    }
    int find(int x){
        if(x==root[x]) return x;
        return root[x] = find(root[x]);        
    }
    void connect(int x, int y){
        if(find(x)!=find(y)){
            if(rank[find(y)]<rank[find(x)]) root[find(y)] = find(x);
            else if(rank[find(y)]>rank[find(x)]) root[find(x)] = find(y);
            else{
                root[find(y)] = find(x);
                rank[find(x)]++;
            }
            numOfGroup--;
        }
    }
    bool isConnected(int x, int y){
        return find(x)==find(y);
    }
    int getNumOfGroup(){
        return numOfGroup;
    }
    void printRoot(){
        printVector(root);
    }
    void printRank(){
        printVector(rank);
    }
private:
    vector<int> root;
    vector<int> rank;
    int numOfGroup;
};