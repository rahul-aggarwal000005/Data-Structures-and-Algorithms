class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[](string &a,string &b){
            return a.length() < b.length();
        });
        int n = strs.size();
        string ans = "";
        string word = strs[0];
        for(int i=0;i<word.length();i++){
            char cur = word[i];
            bool check = true;
            for(int j=0;j<n;j++){
                if(strs[j][i] != cur){
                    check = false;
                    break;
                }
            }
            if(!check){
                return ans;
            }
            ans += cur;
        }
        return ans;
    }
};