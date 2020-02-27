// 392. Is Subsequence (https://leetcode.com/problems/is-subsequence/)
// Author: Hritik Gupta

class Solution {
public:
    
    bool go(string s, string t){    
        
        int idx = 0;
        
        for(int i=0; i<t.size(); i++){
            if(s[idx] == t[i])
                idx++;
            
            if(idx >= s.size())
                return true;
        }
        return false;
    }
    
    bool isSubsequence(string s, string t) {
        if(s.size() == 0)
            return true;
        if(t.size() == 0)
            return false;
        
        return go(s, t);
    }
};

/*
   .
"abc" 
"ahbgdc"
      .
*/