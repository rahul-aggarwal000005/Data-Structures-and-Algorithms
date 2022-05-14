class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, n = nums.size();
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[e]){
                if(nums[mid] > target and nums[s] <= target){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            else if(nums[mid] < nums[s]){
                if(target > nums[mid] and nums[e] >= target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            else{
                if(target < nums[mid]){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
        }
        return -1;
    }
};