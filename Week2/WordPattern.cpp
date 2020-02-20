// 290. Word Pattern (https://leetcode.com/problems/word-pattern/)
// Author: Hritik Gupta

class Solution {
public:
    
    vector<string> split(string str){
        vector<string> words;
        string curr = "";
        
        for(int i=0; i<str.size(); i++){
            if(str[i] == ' '){
                words.push_back(curr);
                curr = "";
            }
            else curr += str[i];
        }
        words.push_back(curr);
        return words;
    }
    
    bool wordPattern(string pattern, string str) {
        
        vector<string> words = split(str);
        if(words.size() != pattern.size())
            return false;
        
        unordered_map<char, string> f_hash;
        unordered_map<string, char> b_hash;
        
        for(int i=0; i<pattern.size(); i++){
            if(f_hash.find(pattern[i]) != f_hash.end()){
                if(f_hash[pattern[i]] != words[i])
                    return false;
            }
            f_hash[pattern[i]] = words[i];
        }
        
        for(int i=0; i<words.size(); i++){
            if(b_hash.find(words[i]) != b_hash.end()){
                if(b_hash[words[i]] != pattern[i])
                    return false;
            }
            b_hash[words[i]] = pattern[i];
        }
        
        return true;
    }
};

/*
Approach Similar to 205. Isomorphic Strings

M = number of words in str
N = number of chars in pattern
Time: O(M+N)
Space: O(2*M+N)
*/