// 347. Top K Frequent Elements (https://leetcode.com/problems/top-k-frequent-elements/)
// Author: Hritik Gupta

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == 0 || nums.size() == 0)
            return vector<int> ();
        
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++)
            hash[nums[i]]++;
        
        priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        
        for(auto it=hash.begin(); it!=hash.end(); it++){
            pq.push({it->second, it->first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> res;
        while(pq.size() > 0){
            int ele = pq.top().second;
            res.push_back(ele);
            pq.pop();
        }
        return res;
    }
};