// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res;
    int visited[10][10];
    void helper(vector<vector<int>> &arr,int n,int i,int j,string &ans){
        if(i == n-1 and j == n-1){
            res.push_back(ans);
            return;
        }
        if(arr[i][j] == 0 or visited[i][j]) return;
        visited[i][j] = 1;
        if(i+1 < n and arr[i+1][j] == 1){
            ans += 'D';
            helper(arr,n,i+1,j,ans);
            ans.pop_back();
        }
        if(i-1 >= 0 and arr[i-1][j] == 1){
            ans += 'U';
            helper(arr,n,i-1,j,ans);
            ans.pop_back();
        }
        if(j+1 < n and arr[i][j+1] == 1){
            ans += 'R';
            helper(arr,n,i,j+1,ans);
            ans.pop_back();
        }
        if(j-1 >= 0 and arr[i][j-1] == 1){
            ans += 'L';
            helper(arr,n,i,j-1,ans);
            ans.pop_back();
        }
        visited[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        res.clear();
        string ans = "";
        memset(visited,0,sizeof(visited));
        helper(m,n,0,0,ans);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends