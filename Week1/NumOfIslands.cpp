// 200. Number of Islands (https://leetcode.com/problems/number-of-islands/)
// Author: Hritik Gupta

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        
        int xdir[] = {-1, 0, 1, 0};
        int ydir[] = {0, 1, 0, -1};
        
        for(int dir=0; dir<4; dir++){
            int newx = xdir[dir] + i;
            int newy = ydir[dir] + j;
            
            if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy] == '1')
                dfs(grid, newx, newy);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};

/*

11110
11010
11000
00000

1) Iterate through the grid, if encountered a land (1):
    - start dfs from that coordinate to see how far that land goes
    - keep marking visited coordinates as 0
2) For every dfs invokation, increment a counter
3) return count

Time: O(MN)
Space: O(1)

*/