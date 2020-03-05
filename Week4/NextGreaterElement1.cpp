//496. Next Greater Element I (https://leetcode.com/problems/next-greater-element-i/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() == 0)
            return vector<int> ();

        vector<int> res(nums2.size());
        stack<int> s;
        
        unordered_map<int, int> hash;
        
        for(int i=0; i<nums2.size(); i++){
            hash[nums2[i]] = i;
            if(s.empty()){
                s.push(i);
                continue;
            }
            
            while(!s.empty() && nums2[i] > nums2[s.top()]){
                res[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()){
            res[s.top()] = -1;
            s.pop();
        }
        
        vector<int> ans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            ans[i] = res[hash[nums1[i]]];
        }
        
        return ans;
    }
};


/*

[1,3,4,2]


1


*/