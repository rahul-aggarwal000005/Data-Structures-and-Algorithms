class Solution {
public:
    vector<int> lps(string &s){
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
    int strStr(string haystack, string needle) {
        string s = needle;
        s += '#';
        int k = s.length();
        s += haystack;
        int m = needle.length();
        vector<int> res = lps(s);

        int idx = 0;
        while(k<res.size()){
            if(res[k] == m){
                return idx - m + 1;
            }
            k++;
            idx++;
        }
        return -1;
    }
};