//438. Find All Anagrams in a String (https://leetcode.com/problems/find-all-anagrams-in-a-string/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> res;
        
        map<char, int> p_hash;
        for(int i=0; i<p.size(); i++)
            p_hash[p[i]]++;
        
        map<char, int> hash;
        for(int i=0; i<p.size(); i++)
            hash[s[i]]++;
        
        int i = 0;
        for(int j=p.size(); j<s.size(); j++){
            
            if(p_hash == hash){
                res.push_back(i);
            }
            hash[s[i]]--;
            if(hash[s[i]] < 1)
                hash.erase(s[i]);
            i++;
            hash[s[j]]++;
        }
        if(hash == p_hash)
            res.push_back(i);
        return res;
    }
};

/*
Sliding window approach with a running hash
Time: O(N)
Space: O(N)
*/