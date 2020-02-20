// 205. Isomorphic Strings (https://leetcode.com/problems/isomorphic-strings/)
// Author: Hritik Gupta

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, char> f_hash;
        unordered_map<char, char> b_hash;
        
        for(int i=0; i<s.size(); i++){
            if(f_hash.find(s[i]) != f_hash.end()){
                if(f_hash[s[i]] != t[i])
                    return false;
            }
            f_hash[s[i]] = t[i];
        }
        for(int i=0; i<t.size(); i++){
            if(b_hash.find(t[i]) != b_hash.end()){
                if(b_hash[t[i]] != s[i])
                    return false;
            }
            b_hash[t[i]] = s[i];
        }
        return true;
    }
};


/*
Approach:
1) Keep a index wise character mapping from s to t and vice versa
2) While mapping, if found a char prev seen, having a wrong mapping, return false;

|s| = M
|t| = N
Time: O(M+N)
Space: O(M+N)
*/