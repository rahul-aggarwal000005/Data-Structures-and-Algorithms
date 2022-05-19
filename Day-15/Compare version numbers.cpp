class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0,n = version1.size();
        int j = 0, m = version2.size();
        while(i<n || j < m){
            int n1 = 0, n2 = 0;
            while(i<n and version1[i] == '0') i++;
            while(i<n and version1[i] != '.'){
                n1 = n1 * 10 + (version1[i] - '0');
                i++;
            }
            i++;
            while(j<m and version2[j] == '0') j++;
            while(j<m and version2[j] != '.'){
                n2 = n2 * 10 + (version2[j] - '0');
                j++;
            }
            j++;
            if(n1 < n2) return -1;
            else if(n1 > n2) return 1;
        }
        return 0;
    }
};