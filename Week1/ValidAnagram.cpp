// 242. Valid Anagram (https://leetcode.com/problems/valid-anagram/)
// Author: Hritik Gupta

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        
        for(int i=0; i<s.size(); i++)
            hash1[s[i]-'a']++;
        for(int i=0; i<t.size(); i++)
            hash2[t[i]-'a']++;
        return hash1 == hash2;
    }
};

/*

Approach 1
    1) Sort both the strings
    2) Compare if they are equal => if yes, t is anagram of s
    Time: O(nlgn)
    Space: O(1)
    
Approach 2
    1) Maintain a hashmap of char and frequency for both strings
    2) Compare if they are equal => if yes, t is anagram of s
    Time: O(n)
    Space: O(n)
    
Approach 3
    1) Maintain a 26-sized vector, since all chars are lowercase, for both strings
    2) Compare if the vector are equal => if yes, t is anagram of s
    Time: O(n)
    Space: O(1)

*/
