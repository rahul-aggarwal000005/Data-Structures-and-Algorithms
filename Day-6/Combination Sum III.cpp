class Solution {
public:
    vector<vector<int>> ans;
    void helper(int k,int n,vector<int> &v,int last){
        if(n == 0 and k == 0){
            ans.push_back(v);
            return;
        }
        if(n == 0) return;
        if(k == 0) return;
        for(int i=last+1;i<=9;i++){
            if(i <= n){
                v.push_back(i);
                helper(k-1,n-i,v,i);
                v.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> v;
        helper(k,n,v,0);
        return ans;
    }
};