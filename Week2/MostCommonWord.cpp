// 819. Most Common Word (https://leetcode.com/problems/most-common-word/)
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
            else if(isalpha(str[i])) curr +=  tolower(str[i]);
        }
        words.push_back(curr);
        return words;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        // preprocessing of paragraph
        string paragraph_new = "";
        for(int i=0; i<paragraph.size(); i++){
            if(isalpha(paragraph[i]))
                paragraph_new += paragraph[i];
            else if(paragraph[i] == ' ')
                paragraph_new += " ";
            else{ 
                paragraph_new += paragraph[i];
                paragraph_new += ' ';
            }
        }
        
        unordered_map<string, int> hash;
        for(int i=0; i<banned.size(); i++){
            hash[banned[i]]++;
        }
        
        vector<string> words = split(paragraph_new);
        map<string, int> word_hash;
        for(int i=0; i<words.size(); i++){
            if(words[i] != "")
                word_hash[words[i]]++;
        }
        
        string ans = "";
        int occ = INT_MIN;
        
        for(auto it=word_hash.begin(); it!=word_hash.end(); it++){
            if(hash.find(it->first) == hash.end() && it->second > occ){
                occ = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};