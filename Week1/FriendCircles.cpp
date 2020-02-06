// 547. Friend Circles (https://leetcode.com/problems/friend-circles/)
// Author: Hritik Gupta

class Solution {
public:
    
    int find(vector<int> &parent, int i){
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        
        int circle = M.size();
        
        vector<int> parent(M.size());
        
        for(int i=0; i<parent.size(); i++)
            parent[i] = i;
        
        
        for(int i=0; i<M.size(); i++){
            for(int j=0; j<M[0].size(); j++){
                if(M[i][j] == 1 && i != j){
                    
                    int a = find(parent, i);
                    int b = find(parent, j);
                    
                    if(a != b){
                        parent[a] = b;
                        circle--;
                    }
                    
                }
            }
        }
        
        return circle;      
    }
};

/*
Simple Union Find implementation
This can also be solved via DFS. 

Time: O(N^2)
Space: O(N)
*/