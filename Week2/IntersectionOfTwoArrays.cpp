// 349. Intersection of Two Arrays (https://leetcode.com/problems/intersection-of-two-arrays/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        set<int> hash;
        
        for(int i=0; i<nums1.size(); i++)
            hash.insert(nums1[i]);
        
        set<int> ans;
        for(int i=0; i<nums2.size(); i++){
            if(hash.find(nums2[i]) != hash.end()){
                ans.insert(nums2[i]);
            }
        }
        
        for(auto it=ans.begin(); it!=ans.end(); it++)
            res.push_back(*it);
        
        return res;
    }
};

/*
Simple implementation using 2 sets

Time: O(N+M)
Space: O(N+M+d)
*/