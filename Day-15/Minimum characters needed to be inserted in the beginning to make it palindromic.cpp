vector<int> lps(string s){
    int n = s.length();
    vector<int> res(n,0);
    for(int i=1;i<n;i++){
        int j = res[i-1];
        while(j>0 and s[i] != s[j]){
            j = res[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        res[i] = j;
    }
    return res;
}
int Solution::solve(string A) {
    string s = A;
    reverse(s.begin(),s.end());
    s = A + s;
    vector<int> res = lps(s);
    int ans = res.back();
    int n = A.length();
    if(ans >= n) return 0;
    ans = n - ans;
    return ans;
}
