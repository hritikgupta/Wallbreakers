// 14. Longest Common Prefix (https://leetcode.com/problems/longest-common-prefix/)
// Author: Hritik Gupta

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        
        if(strs.size() == 0)
            return res;
        
        string first = strs[0];
        int i = 0;
        
        while(i < first.size()){
            char c = first[i];
            bool consider = true;
            for(int j = 1; j<strs.size(); j++){
                if(strs[j][i] != c || i>strs[j].size()){
                    consider = false;
                    break;
                }
            }
            if(consider)
                res += c;
            else break;
            i++;
        }
        return res;
    }
};


/*
   .
"flower" 
                    .  
["flower","flow","flight"]

prefix = "fl"
*/