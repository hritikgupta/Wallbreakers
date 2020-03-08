// 207. Course Schedule (https://leetcode.com/problems/course-schedule/)
// Author: Hritik Gupta

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0)
            return true;
        
        vector<int> indegree(numCourses, 0);
        map<int, set<int> > adj;
        
        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].insert(a);
            indegree[a]++;
        }
        
        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        
        int count = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            count++;
            
            set<int> neighs = adj[temp];
            for(auto it=neighs.begin(); it!=neighs.end(); it++){
                if(--indegree[*it] == 0)
                    q.push(*it);
            }
        }
        
        return count == numCourses;
    }
};