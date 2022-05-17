vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<pair<int,int>> st;
    int n = A.size();
    vector<int> res(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top().second > A[i]){
            res[st.top().first] = A[i];
            st.pop();
        }
        st.push({i,A[i]});
    }
    return res;
}
