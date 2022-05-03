class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        int i = 0,n = nums.size();
        while(i<n and temp[i] == nums[i]){
            i++;
        }
        int j = n-1;
        while(j>=0 and temp[j] == nums[j]){
            j--;
        }
        int len = j - i + 1;
        if(j <= i){
            return 0;
        }
        return len;
    }
};