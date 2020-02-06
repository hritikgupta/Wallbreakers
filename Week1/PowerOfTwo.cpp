//231. Power of Two (https://leetcode.com/problems/power-of-two/)
// Author: Hritik Gupta

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0)
            return false;
   
        // Approach 1
        /* 
         int num_bits = (int)log2(n)+1;
         int k = 1<<(num_bits-1) ;
        
         return (k == n);
        */
        
        // Approach 2
        return !(n & (n-1));
    }
};

/*

2 : 10
4 : 100
8 : 1000
16: 10000 
...

Approach 1
    1) Count number of bits in given number
    2) Shift 1 to the right count-1 times
    3) The obtained number should be equal to the given number to be a power of 2
Approach 2
    Except the most sign bit, all the bits are 0 in powers of 2
    1) We get its inverse if we subtract 1 from it
    2) Take AND with the inverse and do a NOT. If all bits are set => Means its a power of 2

Time: O(1)
Space: O(1)

*/