// 557. Reverse Words in a String III (https://leetcode.com/problems/reverse-words-in-a-string-iii/)
// Author: Hritik Gupta

class Solution {
public:
    
    vector<string> split(string s){
        vector<string> words;
        string curr = "";
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                words.push_back(curr);
                curr = "";
            }
            else curr += s[i];
        }
        words.push_back(curr);
        return words;
    }
    
    string reverseWords(string s) {
        
        vector<string> words;
        words = split(s);
        
        string ans = "";
        
        for(int i=0; i<words.size(); i++){
            string word = words[i];
            reverse(word.begin(), word.end());
            
            for(int j=0; j<word.size(); j++)
                ans += word[j];
            
            if(i != words.size()-1)
                ans += ' ';
        }
        return ans;
    }
};


/*
1) Split the given string via spaces into words
2) Reverse the individual words
3) Form the string again with reversed words

Time: O(N)
Space: O(N)
*/