// 416. Partition Equal Subset Sum (https://leetcode.com/problems/partition-equal-subset-sum/)
// Author: Hritik Gupta

class Solution {
public:
    
    bool go(vector<int> &nums, int i, int sum, int total, vector<vector<bool> > &dp, vector<vector<bool> > &vis){
        if(sum*2 == total)
            return true;
        
        if(i >= nums.size() || sum > total/2)
            return false;
        
        if(vis[i][sum])
            return dp[i][sum];
        
        vis[i][sum] = true;
        dp[i][sum] = go(nums, i+1, sum+nums[i], total, dp, vis) || go(nums, i+1, sum, total, dp, vis);
        return dp[i][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int total = 0;
        
        for(int i=0; i<nums.size(); i++)
            total += nums[i];
        
        if(total %2 != 0)
            return false;
        
        
        vector<vector<bool> > dp(nums.size(), vector<bool> (total/2, false));
        vector<vector<bool> > vis(nums.size(), vector<bool> (total/2, false));
        
        return go(nums, 0, 0, total, dp, vis);
    }
};