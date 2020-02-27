// 121. Best Time to Buy and Sell Stock (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
// Author: Hritik Gupta

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans = 0, curr_min = INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            curr_min = min(prices[i], curr_min);
            
            int diff = prices[i] - curr_min;
            ans = max(ans, diff);
        }
        
        return ans;
    }
};