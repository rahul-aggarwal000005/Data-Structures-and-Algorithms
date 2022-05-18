class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<=j and s[i] == ' ') i++;
        while(i<=j and s[j] == ' ') j--;
        string ans = "";
        vector<string> arr;
        string temp = "";
        while(i <= j){
            if(s[i] == ' '){
                arr.push_back(temp);
                temp = "";
                while(i <= j and s[i] == ' ') i++;
            }
            else{
                temp += s[i];
                i++;
            }
        }
        arr.push_back(temp);
        for(int i = arr.size()-1;i>=0;i--){
            ans += arr[i];
            ans += " ";
        }
        
        ans.pop_back();
        
        return ans;
    }
};