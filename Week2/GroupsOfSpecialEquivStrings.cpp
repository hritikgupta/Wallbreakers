// 893. Groups of Special-Equivalent Strings (https://leetcode.com/problems/groups-of-special-equivalent-strings/)
// Author: Hritik Gupta

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        
        set<string> res;
        for(int i=0; i<A.size(); i++){
            
            string odd = "";
            string even = "";
            string curr = A[i];
            
            for(int j=0; j<curr.size(); j++){
                if(j%2 == 0)
                    even += curr[j];
                else odd += curr[j];
            }
            
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            
            string temp = even+odd;
            res.insert(temp);
        }
        
        return res.size();
    }
};