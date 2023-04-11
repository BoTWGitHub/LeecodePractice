/*
Given a string input representing the file system in the explained format
, return the length of the longest absolute path to a file in the abstracted file system. 
If there is no file in the system, return 0.

Note that the testcases are generated such that the file system is valid and no file or directory name has length 0.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> mem;
        int n = input.size();
        int i = 0;
        int layer = 0;
        string temp = "";
        int res = 0;
        while(i<n){
            if(input[i]=='\n'){
                if(layer==mem.size()){
                    mem.push_back(temp);
                }
                else{
                    mem[layer] = temp;
                }
                layer = 0;
                temp.clear();
                i++;
            }
            else if(input[i]=='\t'){
                layer++;
                i++;
            }
            else if(input[i]=='.'){
                int len = 0;
                for(int j=0;j<layer;j++){
                    len+=(mem[j].size()+1);
                }
                len+=temp.size();
                int j = i;
                while(j<n && input[j]!='\n') j++;
                len+=(j-i);
                i = j;
                res = max(res, len);
            }
            else{
                temp+=input[i++];
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    string input;

    input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << solution.lengthLongestPath(input) << endl;

    input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    cout << solution.lengthLongestPath(input) << endl;

    input = "a";
    cout << solution.lengthLongestPath(input) << endl;
    return 0;
}