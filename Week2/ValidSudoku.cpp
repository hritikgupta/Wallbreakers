// 36. Valid Sudoku (https://leetcode.com/problems/valid-sudoku/)
// Author: Hritik Gupta

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        if(board.size() == 0)
            return false;
        
        // check rows
        for(int i=0; i<board.size(); i++){
            unordered_map<char, int> row_hash;
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] != '.'){
                    if(row_hash.find(board[i][j]) != row_hash.end())
                        return false;
                    row_hash[board[i][j]]++;
                }
            }
        }
        
        
        // check cols
        for(int i=0; i<board.size(); i++){
            unordered_map<char, int> col_hash;
            for(int j=0; j<board[0].size(); j++){
                if(board[j][i] != '.'){
                    if(col_hash.find(board[j][i]) != col_hash.end())
                        return false;
                    col_hash[board[j][i]]++;
                }
            }
        }
        
        // check all the 3x3 squares
        for(int i=0; i<board.size(); i+=3){
            for(int j=0; j<board[0].size(); j+=3){
                unordered_map<char, int> sq_hash;
                
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        if(board[k][l] != '.'){
                            if(sq_hash.find(board[k][l]) != sq_hash.end())
                                return false;
                            sq_hash[board[k][l]]++;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

/*

Time: O(MN)
Space: O(MN)

*/