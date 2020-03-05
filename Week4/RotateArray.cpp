// 189. Rotate Array (https://leetcode.com/problems/rotate-array/)
// Author: Hritik Gupta

class Solution {
public:
    
    void reverse(vector<int> &nums, int x, int y){
        int i = x, j = y;
        
        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};


/*
 .
[1,2,3,4,5,6,7]
[7 6 5 4 3 2 1]
[5 6 7 4 3 2 1]
[5 6 7 1 2 3 4]


*/