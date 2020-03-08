// 785. Is Graph Bipartite? (https://leetcode.com/problems/is-graph-bipartite/)
// Author: Hritik Gupta

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() == 0)
            return false;
        
        int N = graph.size();
        vector<int> colors(N, 0);
        
        for(int i=0; i<N; i++){
            if(colors[i] != 0)
                continue;
            
            queue<int> q;
            q.push(i);
            colors[i] = true;
            
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                
                int col = colors[temp];
                vector<int> neighs = graph[temp];
                
                for(int j=0; j<neighs.size(); j++){
                    if(colors[neighs[j]] == 0){
                        colors[neighs[j]] = -1*col;
                        q.push(neighs[j]);
                    }
                    else if(colors[neighs[j]] == col)
                        return false;
                }   
            }
        }
        return true;
    }
};