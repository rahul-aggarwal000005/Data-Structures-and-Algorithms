class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        // 1 4 3 2
        // 2 4 3 1
        while(i>=0 and nums[i] >= nums[i+1]){
            i--;
        }
        
        if(i == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int idxToSwap = i;
        int j;
        for(j=n-1;j>i;j--){
            if(nums[j] > nums[idxToSwap]){
                break;
            }
        }
        swap(nums[idxToSwap],nums[j]);
        reverse(nums.begin()+idxToSwap+1,nums.end());
    }
};