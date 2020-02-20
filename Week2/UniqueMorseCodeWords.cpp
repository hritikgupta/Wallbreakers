//804. Unique Morse Code Words (https://leetcode.com/problems/unique-morse-code-words/)
// Author: Hritik Gupta

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> hash;
        
        for(int i=0; i<words.size(); i++){
            string res = "";
            string curr = words[i];
            for(int j=0; j<curr.size(); j++){
                res += morse[curr[j]-'a'];
            }
            hash.insert(res);
        }
        return hash.size();
    }
};

/*
Time: O(N*m)
Space: O(N)
*/