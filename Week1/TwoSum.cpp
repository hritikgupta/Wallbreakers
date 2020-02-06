// 1. Two Sum (https://leetcode.com/problems/two-sum/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        map<int, int> hash;
        
        for(int i=0; i<nums.size(); i++){
            if(hash.find(target-nums[i]) != hash.end()){
                res.push_back(hash[target-nums[i]]);
                res.push_back(i);
            }
            else hash[nums[i]] = i;
        }
        
        return res;
    }
};