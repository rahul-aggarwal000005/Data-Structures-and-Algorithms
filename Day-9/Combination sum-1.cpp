class Solution {
public:
    set<vector<int>> st;
    void helper(vector<int> &arr,int target,vector<int> &v,int idx){
        if(idx == arr.size()) return;
        if(target == 0){
            st.insert(v);
            return;
        }
        if(arr[idx] <= target){
            v.push_back(arr[idx]);
            helper(arr,target-arr[idx],v,idx);
            v.pop_back();
        }
        helper(arr,target,v,idx+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
        vector<int> v;
        st.clear();
        helper(candidates,target,v,0);
        vector<vector<int>> res;
        for(auto x:st){
            res.push_back(x);
        }
        return res;
    }
};