// 389. Find the Difference (https://leetcode.com/problems/find-the-difference/)
// Author: Hritik Gupta

class Solution {
public:
    char findTheDifference(string s, string t) {
     
        vector<int> hash(26, 0);
        
        for(int i=0; i<t.size(); i++)
            hash[t[i]-'a']++;
        
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']--;
        }
        
        char ans;
        for(int i=0; i<hash.size(); i++){
            if(hash[i] > 0){
                ans = i;
                break;
            }
        }
        return char(ans+'a');
    }
};

/*
Time: O(N)
Space: O(1) // constant
*/