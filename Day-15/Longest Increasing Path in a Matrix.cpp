class Solution {
public:
    vector<vector<int>> dp;
    int visited[500][500];
    int dfs(vector<vector<int>> &arr,int i,int j,int n,int m){
        if(visited[i][j]) return dp[i][j];
        visited[i][j] = 1;
        int cur = arr[i][j];
        int val = dp[i][j];
        if((i+1) < n and arr[i+1][j] > cur){
            val = max(val,1 + dfs(arr,i+1,j,n,m));
        }
        if((i-1)>=0 and arr[i-1][j] > cur){
            val = max(val,1 + dfs(arr,i-1,j,n,m));
        }
        if((j+1)< m and arr[i][j+1] > cur){
            val = max(val,1 + dfs(arr,i,j+1,n,m));
        }
        if((j-1)>=0 and arr[i][j-1] > cur){
            val = max(val,1 + dfs(arr,i,j-1,n,m));
        }
        return dp[i][j] = val;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(visited,0,sizeof(visited));
        int n = matrix.size(), m = matrix[0].size();
        dp.resize(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    dfs(matrix,i,j,n,m);           
                }
            }
        }
        int val = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<dp[i][j]<<" ";
                val = max(val,dp[i][j]);
            }
            // cout<<endl;
        }
        return val;
    }
};