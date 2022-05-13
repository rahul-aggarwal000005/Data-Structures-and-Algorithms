class Solution {
public:
    set<vector<int>> st;
    
    void helper(vector<int> &nums,vector<int> &v,int idx){
        if(idx == nums.size()){
            st.insert(v);
            return;
        }
        v.push_back(nums[idx]);
        helper(nums,v,idx+1);
        v.pop_back();
        helper(nums,v,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        st.clear();
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(),nums.end());
        helper(nums,v,0);
        for(auto x:st){
            res.push_back(x);
        }
        return res;
    }
};