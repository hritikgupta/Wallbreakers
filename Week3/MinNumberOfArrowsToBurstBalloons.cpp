// 452. Minimum Number of Arrows to Burst Balloons (https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)
// Author: Hritik Gupta

bool cmp(vector<int> &a, vector<int> &b){
    // if(a[0] != b[0])
        // return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size() == 0)
            return 0;
        
        sort(points.begin(), points.end(), cmp);
        
        int count = 1;
        int i = 0;
        int curr_start = points[i][0];
        int last_end = points[i][1];
        
        for(int i=1; i<points.size(); i++){
            if(points[i][0] > last_end){
                count++;
                last_end = points[i][1];
            }
        }
        
        return count;
    }
};

/*
   .
[1, 5], [1,6], [2,8], [7, 12], [10, 16]
          .
                 . 
start[i] <= curr[i].end
end[i] >= curr[i].end
   .
[[1,2],[3,4],[5,6],[7,8]]
         .
*/