// 56. Merge Intervals (https://leetcode.com/problems/merge-intervals/)
// Author: Hritik Gupta

bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        
        if(intervals.size() == 0)
            return res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        res.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++){
            
            int last_start = res[res.size()-1][0]; 
            int last_end = res[res.size()-1][1];
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            // case of merge
            if(curr_start <= last_end){
                int end = max(curr_end, last_end);
                res.pop_back();
                
                res.push_back({last_start, end});
            }
            else res.push_back({curr_start, curr_end});
        }   
        return res;
        
    }
};