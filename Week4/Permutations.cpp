// 46. Permutations (https://leetcode.com/problems/permutations/)
// Author: Hritik Gupta

class Solution {
public:
    
    void solve(vector<vector<int> > &res, vector<int> nums, vector<int> dummy){
        if(nums.size() == 0){
            res.push_back(dummy);
        }
        
        for(int i=0; i<nums.size(); i++){
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            dummy.push_back(nums[i]);
            solve(res, temp, dummy);
            dummy.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        
        if(nums.size() == 0)
            return res;
        
        vector<int> dummy;
        solve(res, nums, dummy);
        
        return res;
    }
};

/*
 .
[1,2,3]

*/