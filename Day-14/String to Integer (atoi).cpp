class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        while(i<n and s[i] == ' ') i++;
        if(i == n) return 0;
        int signBit = 1;
        if(s[i] == '-'){
            signBit = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        long long val = 0;
        while(i<n and isdigit(s[i])){
            if(val >= INT_MAX) break;
            val = val*10 + (s[i]-'0');
            i++;
        }
        val = val * signBit;
        if(val >= INT_MAX) return INT_MAX;
        if(val <= INT_MIN) return INT_MIN;
        return val;
    }
};