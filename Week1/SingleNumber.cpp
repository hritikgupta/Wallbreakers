// 136. Single Number (https://leetcode.com/problems/single-number/)
// Author: Hritik Gupta

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        
        return ans;
    }
};

/*
1) XOR of even-frequency elements becomes zero
2) Since, there is only 1 repeating element, what we'll be left with after xor-ing all the elements is that repeating element 
*/