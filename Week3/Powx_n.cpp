// 50. Pow(x, n) (https://leetcode.com/problems/powx-n/)
// Author: Hritik Gupta

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0 || x == 1)
            return 1;
        
        bool isneg = false;
        if(n < 0){
            isneg = true;
            if(n == INT_MIN){
                if(x == -1)
                    return 1;
                n = INT_MAX;
            }
            else n*= -1;
        }
        
        double ans = 1;
        while(n > 0){
            if(n%2 != 0)
                ans *= x;
            
            x = x*x;
            n>>=1;
        }
        
        if(isneg)
            return 1.0/ans;
        return ans;
    }
};