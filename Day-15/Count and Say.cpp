class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string rec = countAndSay(n-1);
        string ans = "";
        int cnt = 1;
        char last = rec[0];
        for(int i=1;i<rec.length();i++){
            if(last == rec[i]){
                cnt++;
            }
            else{
                ans += to_string(cnt);
                ans += last;
                cnt = 1;
                last = rec[i];
            }
        }
        ans += to_string(cnt);
        ans += last;
        return ans;
    }
};