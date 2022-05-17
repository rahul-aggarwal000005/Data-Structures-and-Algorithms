class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> d;
        for(int i=0;i<k;i++){
            while(!d.empty() and d.back().first < nums[i]){
                d.pop_back();
            }
            d.push_back({nums[i],i});
        }
        vector<int> res;
        for(int i=k;i<nums.size();i++){
            res.push_back(d.front().first);
            while(!d.empty() and d.front().second <= i-k){
                d.pop_front();
            }
            while(!d.empty() and d.back().first < nums[i]){
                d.pop_back();
            }
            d.push_back({nums[i],i});
        }
        res.push_back(d.front().first);
        return res;
    }
};