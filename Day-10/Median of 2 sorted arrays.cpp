class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i++]);
            }
            else{
                res.push_back(nums2[j++]);
            }
        }
        
        while(i<n){
            res.push_back(nums1[i++]);
        }
        
        while(j<m){
            res.push_back(nums2[j++]);
        }
        
        int size = (n+m);
        if(size % 2 == 0){
            int x = size / 2;
            int y = size / 2 - 1;
            double ans = ((res[x] + res[y])*1.0) / 2.0;
            return ans;
        }
        else{
            double ans = res[size/2] * 1.0;
            return ans;
        }
    }
};