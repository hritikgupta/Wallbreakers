// 125. Valid Palindrome (https://leetcode.com/problems/valid-palindrome/)
// Author: Hritik Gupta

class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.size() <= 1)
            return true;
        
        int i = 0, j = s.size()-1;
        
        while(i < j){
            if(isalnum(s[i]) && isalnum(s[j])){
                char a = isalpha(s[i])?tolower(s[i]):s[i];
                char b = isalpha(s[j])?tolower(s[j]):s[j];
                
                if(a == b){
                    i++;
                    j--;
                }
                else return false;
            }
            else{
                if(!isalnum(s[i]))
                    i++;
                else
                    j--;
            }
        }
        return true;
    }
};


/*

1) Init 2 pointers at the beginning and end of the array
2) Keep comparing if the character is alphanumeric; if not alphanumeric, move ahead
3) If tolower(chars) not same, return false
4) Iteration ends => return true

            .
"A man, a plan, a canal: Panama"
                     .    
    .                    
"race a car"
      .  
*/