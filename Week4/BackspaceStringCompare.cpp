//844. Backspace String Compare (https://leetcode.com/problems/backspace-string-compare/)
// Author: Hritik Gupta

class Solution {
public:
    
    string helper(string S){
        string res = "";
        
        for(int i=0; i<S.size(); i++){
            if(S[i] == '#'){
                if(res.size() > 0)  
                    res.pop_back();
            }
            else res += S[i];
        }
        return res;
    }
    
    bool backspaceCompare(string S, string T) {
        if(S == T)
            return true;
        
        string a = helper(S);
        string b = helper(T);
        
        return (a == b);
    }
};

/*

"f"
"f#o##f"

*/