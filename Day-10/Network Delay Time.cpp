class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int val = 1e9 + 10;
        vector<int> dist(n+1,val);
        queue<int> q;
        map<int,vector<pair<int,int>>> mp;
        for(auto x:times){
            mp[x[0]].push_back({x[1],x[2]});
        }
        q.push(k);
        dist[k] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto x:mp[cur]){
                if(dist[x.first] > (dist[cur] + x.second)){
                    dist[x.first] = dist[cur] + x.second;
                    q.push(x.first);
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(dist[i] == val) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};