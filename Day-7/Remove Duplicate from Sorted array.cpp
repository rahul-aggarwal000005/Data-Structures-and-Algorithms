class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = nums[0];
        int left = 1;
        int i = 1, n = nums.size();
        while(i < n){
            while(i < n and nums[i] == last){
                i++;
            }
            if(i == n){
                break;
            }
            nums[left] = nums[i];
            last = nums[i];
            left++;
        }
        return left;
    }
};