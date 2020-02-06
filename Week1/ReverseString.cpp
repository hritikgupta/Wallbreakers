// 344. Reverse String (https://leetcode.com/problems/reverse-string/)
// Author: Hritik Gupta

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i = 0, j = s.size()-1;
        
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

/*

1) Maintain 2 pointers at the beginning and end of vector
2) Move them inwards and keep swapping chars

Time: O(n)
Space: O(1)

*/