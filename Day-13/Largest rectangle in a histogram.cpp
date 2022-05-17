class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n,n);
        vector<int> left(n,-1);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top().first > arr[i]){
                right[st.top().second] = i;
                st.pop();
            }
            st.push({arr[i],i});
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top().first > arr[i]){
                left[st.top().second] = i;
                st.pop();
            }
            st.push({arr[i],i});
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i] - left[i] - 1)*arr[i]);
        }
        return ans;
    }
};