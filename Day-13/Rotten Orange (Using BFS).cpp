class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int found = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
                found += grid[i][j];
            }
        }
        
        if(!found) return 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};
        int times = -1;
        while(!q.empty()){
            int sz = q.size();
            times++;
            for(int i=0;i<sz;i++){
                auto cur = q.front();
                q.pop();
                int cx = cur.first, cy = cur.second;
                // cout<<cx<<" "<<cy<<" "<<times<<endl;
                for(int j=0;j<4;j++){
                    int x = cx + dx[j], y = cy + dy[j];
                    if(x < 0 or y < 0 or x >= n or y >= m or 
                       vis[x][y] or grid[x][y] != 1) continue;
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and vis[i][j] == false) return -1;
            }
        }
        return times;
    }
};