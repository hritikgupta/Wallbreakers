// 455. Assign Cookies (https://leetcode.com/problems/assign-cookies/)
// Author: Hritik Gupta

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        int count = 0;
        
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                count++;
                i++;
                j++;
            }
            else if(g[i] > s[j])
                j++;
        }
        
        return count;
    }
};


/*
    .
g[1,2,3,4,5], 
s[1,1,5,6,7]
    .
*/