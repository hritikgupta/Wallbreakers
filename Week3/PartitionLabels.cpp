// 763. Partition Labels (https://leetcode.com/problems/partition-labels/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        
        if(S.size() == 0)
            return res;
        
        map<char, int>hash;
        for(int i=0; i<S.size(); i++)
            hash[S[i]] = i;
        
        int last_part = 0, max_idx = INT_MIN;
        for(int i=0; i<S.size(); i++){
            max_idx = max(max_idx, hash[S[i]]);
            
            if(i == max_idx){
                res.push_back(i-last_part+1);
                last_part = i+1;
            }
        }
        
        
        return res;
        
    }
};

/*

defegdehijhklij

currmax = 14
d 14
e 15
f 11
g 13
h 19
i 22
j 23

*/