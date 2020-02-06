//520. Detect Capital (https://leetcode.com/problems/detect-capital/)
// Author: Hritik Gupta

class Solution {
public:
    
    bool allcaps(string s){
        for(int i=0; i<s.size(); i++)
            if(islower(s[i]))
                return false;
        return true;
    }
    bool alllower(string s){
        for(int i=0; i<s.size(); i++)
            if(isupper(s[i]))
                return false;
        return true;
    }
    
    bool detectCapitalUse(string word) {
        
        if(word.size() == 0)
            return true;
        
        int first = word[0];
        
        if(isupper(first)){
            // all or none should be capital
            return allcaps(word.substr(1, word.size())) || alllower(word.substr(1, word.size()));
        }
        else{
            // none should be capital
            return alllower(word);
        }
        return false;
    }
};


/*
Time: O(n); |word| = n
Space: O(1)
*/