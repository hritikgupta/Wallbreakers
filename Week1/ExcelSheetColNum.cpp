//171. Excel Sheet Column Number (https://leetcode.com/problems/excel-sheet-column-number/)
// Author: Hritik Gupta

class Solution {
public:
    int titleToNumber(string s) {
        
        int ans = 0;
        int power = 0;
        
        for(int i=s.size()-1; i>=0; i--){
            ans += (s[i]-'A'+1) * pow(26, power);
            power++;
        }
        
        return ans;
        
    }
};

/*

"AB" => 26 * 1 + 2 
"BC" => 26 * 2 + 3
"ZY" => 26 * 26 + 25

"AAB" => 26^2 * 1 + 26^1 * 1 + 26^0 * 2
Analogous to binary to decimal conversion, but with base 26

*/