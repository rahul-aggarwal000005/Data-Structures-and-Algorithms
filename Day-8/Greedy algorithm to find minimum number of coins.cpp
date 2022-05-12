// Greedy Appraoch
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(),coins.end());
    int ans = 0;
    for(int i=coins.size()-1;i>=0;i--){
        int total = amount / coins[i];
        int amt = total * coins[i];
        ans += total;
        amount -= amt;
    }
    if(amount != 0) return -1;
    return ans;
}

// DP approach
class Solution {
public:
    long long dp[20000];
    long long helper(vector<int> &a,int amt){
        
        if(amt == 0) return 0ll;
        if(dp[amt] != -1) return dp[amt];
        long long res = INT_MAX;
        for(auto x:a){
            if(amt >= x){
                res = min(res,1ll + helper(a,amt-x));
            }
        }
        return dp[amt] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        long long val = helper(coins,amount);
        if(val >= INT_MAX) return -1;
        return val;
    }
};