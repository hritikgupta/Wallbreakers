// 868. Binary Gap (https://leetcode.com/problems/binary-gap/)
// Author: Hritik Gupta

class Solution {
public:
    int binaryGap(int N) {
            
        int count = -1;
        int ans = 0;
        
        while(N > 0){
            
            int last = N&1;
            
            if(last == 0 && count >= 0){
                count++;
            }
            else if(last == 1){
                ans = max(ans, count+1);
                count = 0;
            }
            
            N >>= 1;
        }
        
        return ans;
    }
};


/*
       . 
 0 1 0 1 1 0
 count = 0
 
 Approach
 1) Iterate over the bits of the number starting from the Least Significant Bit
 2) Check if it is 0 or 1
    - if its a 0, and we've never seen a 1 before, discard it
    - else keep a count on the number of zeroes
    - on encountering a 1, update your ans
    
 Time: O(N)
 Space: O(1)

*/