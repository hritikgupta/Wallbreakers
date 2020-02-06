// 832. Flipping an Image(https://leetcode.com/problems/flipping-an-image/)
// Author: Hritik Gupta

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        vector<vector<int> > res = A;
        
        int r = A.size();
        int c = A[0].size();
        
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                res[i][j] = A[i][c-j-1]; // flip
                res[i][j] ^= 1; // invert
            }
        }        
        return res;
    }
};


/*
    Time: O(MN)
    Space: O(MN)
*/