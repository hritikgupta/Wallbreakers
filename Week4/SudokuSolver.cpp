// 37. Sudoku Solver (https://leetcode.com/problems/sudoku-solver/)
// Author: Hritik Gupta

class Solution {
public:
    
    pair<int, int> findEmpty(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(board[i][j] == '.')
                    return {i, j};
        return {-1, -1};
    }
    
    bool isSafe(vector<vector<char>>& board, int row, int col, int num){
        
        for(int i=0; i<board.size(); i++){
            if(board[i][col] == num+'0')
                return false;
        }
        for(int i=0; i<board[0].size(); i++){
            if(board[row][i] == num+'0')
                return false;
        }
        
        int temp_row = row - row%3;
        int temp_col = col - col%3;
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i + temp_row][j + temp_col] == num+'0')
                    return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        pair<int, int> unalloc = findEmpty(board);
        pair<int, int> garbage = {-1, -1};
        if(unalloc == garbage)
            return true;
        
        int row = unalloc.first;
        int col = unalloc.second;
        
        for(int choice=1; choice<=9; choice++){
            if(isSafe(board, row, col, choice)){
                
                board[row][col] = choice + '0';
                
                if(solve(board))
                    return true;
                
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        
        solve(board);
    }
};