// 856. Score of Parentheses (https://leetcode.com/problems/score-of-parentheses/)
// Author: Hritik Gupta

class Solution {
public:
    int scoreOfParentheses(string S) {
        if(S.size() == 0)
            return 0;
        
        int ans = 0;
        stack<int> s;
        
        for(int i=0; i<S.size(); i++){
            if(S[i] == '('){
                s.push(ans);
                ans = 0;
            }
            else{
                int temp = s.top();
                s.pop();
                ans = temp + max(1, 2*ans);
            }
        } 
        
        return ans;
    }
};

/*


"(()(()))" = 2*(1 + 2) = 6


(, 1
(, 0
*/