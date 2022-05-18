class Solution {
public:
    map<int,vector<int>> g;
    vector<vector<int>> res;    
    vector<int> visited;
    vector<int> par,cur,lt;
    int time = 1;
    
    void dfs(int node,int p){
        cur[node] = lt[node] = time;
        par[node] = p;
        time++;
        visited[node] = 1;
        for(auto x:g[node]){
            if(x == p) continue;
            if(!visited[x]){
                dfs(x,node);
                lt[node] = min(lt[node],lt[x]);
                if(lt[x] > cur[node]){
                    res.push_back({node,x});
                }
            }
            else{
                lt[node] = min(lt[node],cur[x]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.clear();
        res.clear();
        visited.resize(n,false);
        lt.resize(n,0);
        par.resize(n,0);
        cur.resize(n,0);
        for(auto x:connections){
            int ai = x[0];
            int bi = x[1];
            g[ai].push_back(bi);
            g[bi].push_back(ai);
        }
        dfs(0,-1);
        
        return res;
    }
};