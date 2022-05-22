// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
map<int,vector<int>> g;
int visited[102];
bool canAssign(int cur,int color){
    for(auto x:g[cur]){
        if(visited[x] == color) return false;
    }
    return true;
}
bool dfs(int cur,int n,int m){
    if(cur == n) return true;
    for(int color=1;color<=m;color++){
        if(!canAssign(cur,color)) continue;
        visited[cur] = color;
        if(dfs(cur+1,n,m)) return true;
        visited[cur] = 0;
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    g.clear();
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j and graph[i][j]){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    
    return dfs(0,n,m);
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends