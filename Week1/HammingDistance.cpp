// 461. Hamming Distance (https://leetcode.com/problems/hamming-distance/)
// Author: Hritik Gupta

class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int count = 0;
        
        while(x > 0 || y > 0){
            
            int a = 0, b = 0;
            
            if(x > 0){
                a = x & 1;
                x = x >> 1;
            }
            if(y > 0){
                b = y & 1;
                y = y >> 1;
            }
            
            if(a != b)
                count++;
        }
        
        return count;
    }
};


/*

The idea is to get the last bit of both the numbers and XOR them.
XOR returns 1 if both the bits are different; keep right shifting the bits of both the numbers until both become 0

Keep a count for the cases when XOR returns a 1.

Time: O(max(x, y))
Space: O(1)

*/