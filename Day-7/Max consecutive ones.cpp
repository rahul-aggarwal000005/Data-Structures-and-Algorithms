class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int ans = 0;
        for(auto x:nums){
            if(x == 1){
                cur++;
            }
            else{
                cur = 0;
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};