// 213. House Robber II (https://leetcode.com/problems/house-robber-ii/)
// Author: Hritik Gupta

class Solution {
public:
    
    int go(vector<int> &nums, int i, vector<int> &dp){
        if(i >= nums.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = max(go(nums, i+1, dp), nums[i] + go(nums, i+2, dp));
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), -1);
        vector<int> temp = nums;
        
        temp.erase(temp.begin());
        nums.erase(nums.begin() + nums.size()-1);
        
        int a = go(nums, 0, dp);
        
        vector<int> dp1(nums.size(), -1);
        int b = go(temp, 0, dp1);
        
        return max(a, b) ;
    }
};