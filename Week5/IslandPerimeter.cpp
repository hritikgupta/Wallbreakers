// 463. Island Perimeter (https://leetcode.com/problems/island-perimeter/)
// Author: Hritik Gupta

class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j < 0 || i>=grid.size() || j>=grid[0].size())
            return 1;
        
        if(grid[i][j] == 0)
            return 1;
        if(grid[i][j] == -1)
            return 0;
        
        grid[i][j] = -1;
        int count = 0;
        
        int xdir[] = {-1, 0, 1, 0};
        int ydir[] = {0, 1, 0, -1};
        for(int dir = 0; dir < 4; dir++){
            int newx = i + xdir[dir];
            int newy = j + ydir[dir];
            
            count += dfs(grid, newx, newy);
        }
        return count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};