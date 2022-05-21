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