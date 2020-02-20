// 645. Set Mismatch (https://leetcode.com/problems/set-mismatch/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        vector<int> hash(nums.size(), 1);
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]-1]--;
        }
        
        vector<int> res;
        int a = 0, b = 0; // insert a first
        
        for(int i=0; i<hash.size(); i++){
            if(hash[i] == -1)
                a = i+1;
            else if(hash[i] == 1)
                b = i+1;
        }
        res.push_back(a);
        res.push_back(b);
        
        return res;
    }
};

/*
Time: O(N) // Two iterations
Space: O(N) 
*/