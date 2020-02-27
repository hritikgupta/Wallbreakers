// 72. Edit Distance (https://leetcode.com/problems/edit-distance/)
// Author: Hritik Gupta

class Solution {
public:
    
    int go(string a, string b, int i, int j, vector<vector<int> > &dp){
        
        if(i == a.size())
            return b.size()-j;
        if(j == b.size())
            return a.size()-i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int &ans = dp[i][j];
        
        if(a[i] == b[j])
            ans = go(a, b, i+1, j+1, dp);
        
        else ans = 1+min(go(a, b, i+1, j, dp), min( go(a, b, i+1, j+1, dp), go(a, b, i, j+1, dp) ) );
        
        return ans;
    }
    
    
    int minDistance(string word1, string word2) {
        
        vector<vector<int> > dp(word1.size(), vector<int> (word2.size(), -1));
        return go(word1, word2, 0, 0, dp);     
    }
};

/*
            .  
word1 = "rhorse"
word2 = "ros"
            .

// deletion
go(a, b, i+1, j)

// replace
go(a, b, i+1, j+1)

// insertion
go(a, b, i, j+1)

*/