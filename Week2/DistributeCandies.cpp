//575. Distribute Candies (https://leetcode.com/problems/distribute-candies/)
// Author: Hritik Gupta

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        set<int> hash;
        for(int i=0; i<candies.size(); i++)
            hash.insert(candies[i]);
        
        return min(hash.size(), candies.size()/2);
    }
};

/*
Time: O(N)
Space: O(N)

[1,1,1,1,2,2,2,3,3,3]

count = 1
1 - 0
2 - 1
3 - 1


*/