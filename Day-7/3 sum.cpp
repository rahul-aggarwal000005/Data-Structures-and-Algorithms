class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int s = i+1;
            int e = n-1;
            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0){
                    st.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(sum < 0){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};