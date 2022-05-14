int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int s = 0;
    int e = 1e18;
    
    int total = (n*m)/2;
    int ans = s;
    while(s<=e){
        int val = (s+e)/2;
        int cnt = 0;
        for(int i=0;i<n;i++){
            int x = (lower_bound(A[i].begin(),A[i].end(),val) - A[i].begin());
            cnt += x;
        }
        if(cnt <= total){
            ans = val;
            s = val+1;
        }
        else{
            e = val-1;
        }
    }
    return ans;
}