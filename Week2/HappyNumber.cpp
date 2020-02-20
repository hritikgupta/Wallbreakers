// 202. Happy Number (https://leetcode.com/problems/happy-number/)
// Author: Hritik Gupta

class Solution {
public:
    
    bool isHappy(int n) {
        
        unordered_map<int, int> hash;
        
        while(n != 1){
            
            int agg = 0;
            int temp = n;
            while(temp){
                
                int dig = temp % 10;
                int val = pow(dig, 2);
                
                agg += val;
                temp/=10;
            }    
            
            if(hash.find(agg) != hash.end())
                return false;
            // cout << agg << ' ';
        
            hash[agg]++;
            n = agg;
        }
        return true;
    }
};

/*

Approach: 
1) Keep storing the squared aggregated value in a hashmap
2) If you encounter the same value again, that means that we're stuck in a loop => return false;

Time: O(N) N = |numbe of digits in n|
Space: O(N)

start = 7
49
16 + 91 = 97
81 + 49 = 130
1 + 9 = 10
1 + 0 = 1

start = 23 
4 + 9 = 13
1 + 9 = 10
1 + 0 = 1

start = 53
25 + 9 = 34
9 + 16 = 25
4 + 25 = 29
4 + 81 = 85
65 + 25 = 90

*/