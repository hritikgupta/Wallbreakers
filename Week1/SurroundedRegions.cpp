//130. Surrounded Regions (https://leetcode.com/problems/surrounded-regions/)
// Author: Hritik Gupta

class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j){
        board[i][j] = 'P';
        
        int xdir[] = {-1, 0, 1, 0};
        int ydir[] = {0, 1, 0, -1};
        
        // look in all the 4 directions
        for(int dir=0; dir<4; dir++){
            int newx = xdir[dir] + i;
            int newy = ydir[dir] + j;
            
            if(newx>=0 && newy>=0 && newx<board.size() && newy<board[0].size() && board[newx][newy] == 'O')
                dfs(board, newx, newy);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        if(board.size() == 0)
            return;
        
        int r = board.size(), c = board[0].size();
        // map<pair<int, int>, bool> visited;
        
        for(int i=0; i<c; i++){
            // checking in first row
            if(board[0][i] == 'O')
                dfs(board, 0, i);
            // checking in last row
            if(board[r-1][i] == 'O')
                dfs(board, r-1, i);
        } 
        
        for(int i=0; i<r; i++){
            // checking in first column
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            // checking in last column
            if(board[i][c-1] == 'O')
                dfs(board, i, c-1);
        } 
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
        
    }
};


/*
1) Loop through the border
    - if encountered a O, start a dfs from there
        - convert all Os to 'P'
2) Loop through the board and convert all Os to Xs
3) Convert all Ps back to Os

X X X X
X O O X
X X O X
X O X X

*/