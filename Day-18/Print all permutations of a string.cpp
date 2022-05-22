class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>&arr,int idx,int n){
        if(idx == n){
            res.push_back(arr);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(arr[idx],arr[i]);
            helper(arr,idx+1,n);
            swap(arr[idx],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        int n = nums.size();
        helper(nums,0,n);
        return res;
    }
};