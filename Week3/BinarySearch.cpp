// 704. Binary Search (https://leetcode.com/problems/binary-search/)
// Author: Hritik Gupta

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        
        int low = 0, high = nums.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                low = mid+1;
            else high = mid-1;
        }
        return -1;        
    }
};