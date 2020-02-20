//884. Uncommon Words from Two Sentences (https://leetcode.com/problems/uncommon-words-from-two-sentences/)
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
    
    
    void solve(vector<string> as, vector<string> bs, vector<string> &res){
        unordered_map<string, int> a_hash;
        unordered_map<string, int> b_hash;
        
        for(int i=0; i<as.size(); i++){
            a_hash[as[i]]++;
        }
        for(int i=0; i<bs.size(); i++){
            b_hash[bs[i]]++;
        }
        
        for(auto it=a_hash.begin(); it!=a_hash.end(); it++){
            if(it->second == 1 && b_hash.find(it->first) == b_hash.end())
                res.push_back(it->first);
        }
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        
        vector<string> res;
        vector<string> w_a = split(A);
        vector<string> w_b = split(B);
        
        solve(w_a, w_b, res);
        solve(w_b, w_a, res);
        
        
        return res;
    }
};