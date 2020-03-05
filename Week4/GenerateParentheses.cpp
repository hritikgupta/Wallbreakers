// 22. Generate Parentheses (https://leetcode.com/problems/generate-parentheses/)
// Author: Hritik Gupta

class Solution {
public:
    
    void solve(vector<string> &res, string curr_string, int open, int close, int n){
        if(curr_string.size() == n*2){
            res.push_back(curr_string);
            return;
        }
        if(open < n)
            solve(res, curr_string + '(', open+1, close, n);
        if(close < open)
            solve(res, curr_string + ')', open, close+1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        if(n == 0)
            return res;
        solve(res, "", 0, 0, n);
        return res;
    }
};

/*
n = 2
()()
(())

n = 3
()()()
(())()
()(())
((()))
(()())

( + x + )

*/