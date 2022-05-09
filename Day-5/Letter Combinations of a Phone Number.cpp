class Solution {
public:
    map<int,string> mp;
    vector<string> ans;
    void helper(int i,string s,string res){
        if(i == s.length()){
            ans.push_back(res);
            return;
        }
        int cur = s[i] - '0';
        string temp = mp[cur];
        for(int j=0;j<temp.length();j++){
            helper(i+1,s,res + temp[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        if(digits.length() == 0){
            return ans;
        } 
        ans.clear();
        helper(0,digits,"");
        return ans;
    }
};