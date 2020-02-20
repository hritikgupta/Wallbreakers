// 811. Subdomain Visit Count (https://leetcode.com/problems/subdomain-visit-count/)
// Author: Hritik Gupta

class Solution {
public:
    
    int countdots(string s){
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '.')
                count++;
        }
        return count;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        vector<string> res;
        
        map<string, int> hash;
        
        for(int i=0; i<cpdomains.size(); i++){
            string full_val = cpdomains[i];
            
            int space_idx = full_val.find(' ');
            int freq = stoi(full_val.substr(0, space_idx));
            
            string domain = full_val.substr(space_idx+1, full_val.size()-1);
            hash[domain] += freq;
            int dot_count = countdots(domain);
            
            for(int dot=0; dot<dot_count; dot++){
                int temp_idx = domain.find('.');
                string temp = domain.substr(temp_idx+1, domain.size());
                hash[temp]+=freq;
                domain = temp;
            }
        }
        
        for(auto it=hash.begin(); it!=hash.end(); it++){
            string re = "";
            re += to_string(it->second);
            re += " ";
            re += it->first;
            res.push_back(re);
        }
        
        return res;
    }
};