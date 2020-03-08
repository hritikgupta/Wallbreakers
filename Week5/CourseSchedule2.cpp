// 210. Course Schedule II (https://leetcode.com/problems/course-schedule-ii/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        
        vector<int> indegree(numCourses, 0);
        map<int, set<int> > adj;
        
        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            
            indegree[a]++;
            adj[b].insert(a);
        }
        
        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            res.push_back(temp);
            set<int> neighs = adj[temp];
            
            for(auto it=neighs.begin(); it!=neighs.end(); it++){
                if(--indegree[*it] == 0)
                    q.push(*it);
            }
        }
        
        if(res.size() == numCourses)
            return res;
        return vector<int>();        
    }
};