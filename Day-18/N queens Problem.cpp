class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string>&arr,int x,int y,int n){
        int i = x;
        while(i >= 0){
            if(arr[i][y] == 'Q') return false;
            i--;
        }
        i = x;
        int j = y;
        while(i>=0 and j>=0){
            if(arr[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = x;
        j = y;
        while(i>=0 and j<n){
            if(arr[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void helper(vector<string> &arr,int r,int n){
        if(r == n){
            res.push_back(arr);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(arr,r,i,n)){
                arr[r][i] = 'Q';
                helper(arr,r+1,n);
                arr[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> grid;
        string s = "";
        for(int i=0;i<n;i++){
            s += '.';
        }
        for(int i=0;i<n;i++){
            grid.push_back(s);
        }
        helper(grid,0,n);
        return res;
    }
};