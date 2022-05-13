class Solution {
public:
    vector<vector<string>> res;
    bool isPal(string s){
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,vector<string> &v){
        if(s.length() == 0){
            res.push_back(v);
            return;
        }
        for(int len=1;len<=s.length();len++){
            string cur = s.substr(0,len);
            string rem = s.substr(len);
            if(isPal(cur)){
                v.push_back(cur);
                helper(rem,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        res.clear();
        helper(s,v);
        return res;
    }
};