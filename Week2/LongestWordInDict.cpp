// 720. Longest Word in Dictionary (https://leetcode.com/problems/longest-word-in-dictionary/)
// Author: Hritik Gupta

class Solution {
public:
    
    int compare(string ans, string res){
        
        if(ans.size() > res.size())
            return -1;
        if(ans.size() < res.size())
            return 1;
        
        for(int i=0; i<ans.size(); i++){
            if(ans[i] == res[i])
                continue;
            return ans[i]-res[i];
        }
        return 0;
    }
    
    string longestWord(vector<string>& words) {
     
        
        unordered_map<string, int> hash;
        for(int i=0; i<words.size(); i++){
            hash[words[i]]++;
        }
        
        string ans = "";
        
        for(int i=0; i<words.size(); i++){
        
            string curr = words[i];
            string res = "";
            
            for(int j=0; j<curr.size(); j++){
                string temp = res;
                temp  += curr[j];
                
                if(hash.find(temp) == hash.end())
                    break;
                
                res = temp;
            }
            
            if(compare(ans, res) > 0)
                ans = res;
        }
        
        // cout << compare("apply", "apple");
        
        return ans;
    }
};