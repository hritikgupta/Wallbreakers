// 728. Self Dividing Numbers (https://leetcode.com/problems/self-dividing-numbers/)
// Author: Hritik Gupta

class Solution {
public:
    
    bool check(int n){
        int num = n;
        
        while(n){
            int dig = n%10;
            if(dig == 0)
                return false;
            if(num % dig != 0)
                return false;
            n/=10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        for(int i=left; i<=right; i++){
            if(check(i))
                res.push_back(i);
        }
        return res;
    }
};

/*
Approach: Simple implementation

Time: O(d * n); d = right-left+1; n = highest number
Space: O(d)

*/