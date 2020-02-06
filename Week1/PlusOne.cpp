// 66. Plus One (https://leetcode.com/problems/plus-one/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> res;
        
        int carry = 0, sum = 0;
        
        for(int i=digits.size()-1; i>=0; i--){
            sum = digits[i] + carry;
            if(i == digits.size()-1)
                sum += 1;
            int val = sum % 10;
            carry = (sum > 9)?1:0;
            res.insert(res.begin(), val);
        }
        if(carry)
            res.insert(res.begin(), carry);
        
        return res;
    }
};

/*
boundary condition: 
    1) single element in digits: can be 9 => ["1", "0"];
       else return [digits[0]+1] 
0) start iterating from the end of the vector
1) Keep a carry value and keep on adding as we proceed

*/