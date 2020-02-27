
// 438. Find All Anagrams in a String (https://leetcode.com/problems/find-all-anagrams-in-a-string/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
           vector<int> idxs;
           if(s.empty() || s.length() < p.length()) return idxs;
                      
           sort(p.begin(),p.end());                     
            
           for(int i=0;i<=s.length()-p.length();i++){
                   
                   string str = s.substr(i,p.length());
                   sort(str.begin(),str.end());
                    // cout << str << ' ' ;
                   
                   if(str.compare(p) == 0) idxs.push_back(i);
           }
           
           return idxs;
    }
        
    
};