// 451. Sort Characters By Frequency (https://leetcode.com/problems/sort-characters-by-frequency/)
// Author: Hritik Gupta

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> myhash;
        for(int i=0; i<s.size(); i++)
            myhash[s[i]]++;
        
        priority_queue<pair<int, char> > pq;
        
        for(auto it=myhash.begin(); it!=myhash.end(); it++)
            pq.push({it->second, it->first});
        
        string res = "";
        while(!pq.empty()){
            pair<int, char> temp = pq.top();
            pq.pop();
            
            int f = temp.first;
            for(int i=0; i<f; i++)
                res += temp.second;
        }
        
        return res;
    }
};