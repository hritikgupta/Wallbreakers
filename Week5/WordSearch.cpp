//79. Word Search (https://leetcode.com/problems/word-search/)
// Author: Hritik Gupta

class Solution {
public:

    bool search(vector<vector<char> > &board, int i, int j, string curr, int idx, string word){
        if(curr == word)
            return true;
        if(idx > word.size())
            return false;
        
        int xdir[] = {-1, 0, 1, 0};
        int ydir[] = {0, 1, 0, -1};
        
        for(int dir=0; dir<4; dir++){
            int newx = xdir[dir] + i;
            int newy = ydir[dir] + j;
            
            if(newx>=0 && newy>=0 && newx<board.size() && newy<board[0].size() && board[newx][newy] == word[idx]){
                char x= board[newx][newy];
                curr += board[newx][newy];
                board[newx][newy] = '-';
                if(search(board, newx, newy, curr, idx+1, word))
                    return true;
                curr.pop_back();
                board[newx][newy] = x;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return false;
        
        
        int first = word[0];
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == first){
                    string temp = "";
                    temp += first;
                    board[i][j] = '-';
                    if(search(board, i, j, temp, 1, word))
                        return true;
                    board[i][j] = first;
                }
            }
        }
        return false;
    }
};