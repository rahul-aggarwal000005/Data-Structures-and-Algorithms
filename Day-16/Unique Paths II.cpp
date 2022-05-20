class Solution {
public:
    int dp[200][200];
    int helper(int i,int j,int n,int m,vector<vector<int>> &arr){
        if(i >= n or j >= m) return 0;
        if(arr[i][j] == 1) return 0;
        if(i == n-1 and j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = helper(i+1,j,n,m,arr) + helper(i,j+1,n,m,arr);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int ans = helper(0,0,n,m,obstacleGrid);
        return ans;
    }
};