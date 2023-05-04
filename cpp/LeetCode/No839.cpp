/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. 
Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2)
, and "rats" and "arts" are similar
, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  
Notice that "tars" and "arts" are in the same group even though they are not similar.  
Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
*/
#include <iostream>
#include <vector>

class Solution {
public:
    int numSimilarGroups(std::vector<std::string>& strs) {
        int n = strs.size();
        root = std::vector<int>(n);
        rank = std::vector<int>(n, 1);
        res = n;
        for(int i=0;i<n;i++) root[i] = i;
        
        for(int i=0;i<strs.size()-1;i++){
            for(int j=i+1;j<strs.size();j++){
                if(isSimilar(strs[i], strs[j])){
                    connect(i, j);
                }
            }
        }

        return res;
    }
private:
    std::vector<int> root;
    std::vector<int> rank;
    int res;
    int find(int x){
        if(root[x]==x) return x;
        return root[x] = find(root[x]);
    }
    void connect(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx!=ry){
            if(rank[rx]<rank[y]){
                root[rx] = ry;
            }
            else if(rank[ry]<rank[rx]){
                root[ry] = rx;
            }
            else{
                root[rx] = ry;
                rank[ry]++;
            }
            res--;
        }
    }
    bool isSimilar(std::string& s1, std::string& s2){
        int mismatch = 0;
        for(int i=0;i<s1.size();i++){
            mismatch+=(s1[i]!=s2[i]);
            if(mismatch>2) return false;
        }
        return true;
    }
};

int main(void){
    Solution solution;
    std::vector<std::string> strs;

    strs = {"tars","rats","arts","star"};
    std::cout << solution.numSimilarGroups(strs) << std::endl;

    strs = {"omv","ovm"};
    std::cout << solution.numSimilarGroups(strs) << std::endl;
    return 0;
}