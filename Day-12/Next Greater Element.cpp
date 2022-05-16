class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() and st.top() < nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> res;
        for(auto x:nums1){
            res.push_back(mp[x]);
        }
        return res;
    }
};