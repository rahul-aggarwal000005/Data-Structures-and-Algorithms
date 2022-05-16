class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        int steps = 0;
        int dx[8]= {0,0,-1,-1,-1,1,1,1};
        int dy[8]= {1,-1,0,-1,1,0,-1,1};
        visited[0][0] = 1;
        while(!q.empty()){
            steps++;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto cur = q.front();
                int cx = cur.first;
                int cy = cur.second;
                if(cx == n-1 and cy == m-1) return steps;
                q.pop();
                for(int j=0;j<8;j++){
                    int x = cx + dx[j];
                    int y = cy + dy[j];
                    if(x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 0
                      and !visited[x][y]){
                        q.push({x,y});
                        visited[x][y] = 1;
                    }
                }
            }
        }
        return -1;
    }
};