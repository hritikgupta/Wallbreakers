// 329. Longest Increasing Path in a Matrix (https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)
// Author: Hritik Gupta

class Solution {
public:
    
//     (i, j) => (i+1, j), (i-1, j), (i, j+1), (i, j-1)    
    
    int findMax(vector<int> &arr){
        int val = INT_MIN;
        for(int i=0; i<arr.size(); i++)
            val = max(val, arr[i]);
        return val;
    }
    
    int solve(vector<vector<int> > &grid, int i, int j, int pathLen, int &ans, vector<vector<int> > &dp){
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int xdir[] = {-1, 0, 1, 0};
        int ydir[] = {0, 1, 0, -1};
        
        vector<int> arr;
        
        for(int dir=0; dir<4; dir++){
            
            if(xdir[dir] == -1 && i == 0)
                continue;
            if(ydir[dir] == -1 && j == 0)
                continue;
            if(xdir[dir] == 1 && i == grid.size())
                continue;
            if(ydir[dir] == 1 && j == grid[0].size())
                continue;
            
            int newx = xdir[dir] + i;
            int newy = ydir[dir] + j;
            
            if(newx >=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy] > grid[i][j]){
                arr.push_back(solve(grid, newx, newy, pathLen+1, ans, dp));
            }
        }
        
        int temp = findMax(arr);
        dp[i][j] = max(temp+1, 1);
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        
        int ans = INT_MIN;
        
        vector<vector<int> > dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int path_len = 0;
                int k = solve(matrix, i, j, path_len, ans, dp);
                ans = max(ans, k);
            }
        }
        return ans;
    }
};