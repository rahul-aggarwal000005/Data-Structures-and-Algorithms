class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cur = INT_MAX;
        for(auto x:prices){
            cur = min(cur,x);
            profit = max(profit,x - cur);
        }
        return profit;
    }
};