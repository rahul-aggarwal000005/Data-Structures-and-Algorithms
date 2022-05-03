class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int maxSum = INT_MIN;
        for(auto x:nums){
            cur += x;
            maxSum = max(maxSum,cur);
            if(cur < 0){
                cur = 0;
            }
        }
        return maxSum;
    }
};