//345. Reverse Vowels of a String (https://leetcode.com/problems/reverse-vowels-of-a-string/)
// Author: Hritik Gupta

class Solution {
public:
    
    bool isvowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
    string reverseVowels(string s) {
        
        int i = 0, j = s.size()-1;
        
        while(i < j){
            
            if(isvowel(s[i]) && isvowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!isvowel(s[i]))
                i++;
            else j--;
        }
        
        return s;
    }
};

/*

1) Maintain 2 pointers at the beginning and end of string
2) If at both the positions, we encounter a vowel, we swap and move both the pointers inwards
3) If not a vowel, move that pointer inwards

Time: O(N)
Space: O(1)

*/