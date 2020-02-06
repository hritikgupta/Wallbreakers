// 476. Number Complement (https://leetcode.com/problems/number-complement/)
// Author: Hritik Gupta

class Solution {
public:
    int findComplement(int num) {
        
        int ans = 0;
        int power = 1;
        
        while(num > 0){
            int last = num & 1;
            int k  = last ^ 1;
            
            ans += k * power;
            
            num = num >> 1;
            power = power << 1;
        }
        
        return ans;
    }
};


/*

Reversal of bits
1 ^ 1=> 0
0 ^ 1=> 1
Apply XOR on the least significant bit of number and keep accumulating the result

Time: O(num)
Space: O(1)

*/