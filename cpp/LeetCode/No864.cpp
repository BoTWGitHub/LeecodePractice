/*
You are given an m x n grid grid where:

'.' is an empty cell.
'#' is a wall.
'@' is the starting point.
Lowercase letters represent keys.
Uppercase letters represent locks.
You start at the starting point and one move consists of walking one space in one of the four cardinal directions. 
You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. 
This means that there is exactly one key for each lock, and one lock for each key; 
and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return -1.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<pair<int, int>, int> start;
        int keys = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    start = {{i, j}, 0};
                }
                else if(grid[i][j]>='a' && grid[i][j]<='z'){
                    keys|=(1<<(grid[i][j]-'a'));
                }
            }
        }

        vector<vector<unordered_set<int>>> seen(m, vector<unordered_set<int>>(n));
        queue<pair<pair<int, int>, int>> q;
        q.push(start);
        seen[start.first.first][start.first.second].insert(0);
        int res = 0;
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [cur, k] = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int dx = cur.first+dirs[d];
                    int dy = cur.second+dirs[d+1];
                    int key = k;
                    if(dx>=m || dx<0 || dy>=n || dy<0 || grid[dx][dy]=='#' || seen[dx][dy].count(key)){
                        continue;
                    }
                    seen[dx][dy].insert(key);
                    if(grid[dx][dy]>='A' && grid[dx][dy]<='Z'){
                        if((key&(1<<(grid[dx][dy]-'A')))==0) continue;
                    }
                    else if(grid[dx][dy]>='a' && grid[dx][dy]<='z'){
                        key|=(1<<(grid[dx][dy]-'a'));
                        if(key==keys) return res;
                    }
                    q.push({{dx, dy}, key});
                }
            }
        }
        return -1;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
};

int main(void){
    Solution solution;
    vector<string> grid;

    grid = {"@.a..","###.#","b.A.B"};
    cout << solution.shortestPathAllKeys(grid) << endl;

    grid = {"@..aA","..B#.","....b"};
    cout << solution.shortestPathAllKeys(grid) << endl;

    grid = {"@Aa"};
    cout << solution.shortestPathAllKeys(grid) << endl;

    grid = {"@...a",".###A","b.BCc"};
    cout << solution.shortestPathAllKeys(grid) << endl;

    return 0;
}