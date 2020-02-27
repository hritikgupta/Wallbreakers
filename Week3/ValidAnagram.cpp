// 242. Valid Anagram (https://leetcode.com/problems/valid-anagram/)
// Author: Hritik Gupta

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return (s == t);
    }
};