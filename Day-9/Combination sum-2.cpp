class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int> &arr,int sum,int idx,vector<int>&v){
        if(sum == 0){
            s.insert(v);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(arr[i] > sum) break;
            if(i > 0 and arr[i] == arr[i-1] and i > idx){
                continue;
            }
            v.push_back(arr[i]);
            solve(arr,sum-arr[i],i+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        s.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> arr;
        solve(candidates,target,0,arr);
        vector<vector<int>> res;
        for(auto x:s){
            res.push_back(x);
        }
        return res;
    }
};