class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        for(int i=2;i<=numRows;i++){
            vector<int> nv;
            nv.push_back(1);
            for(int j=1;j<v.size();j++){
                int val = v[j] + v[j-1];
                nv.push_back(val);
            }
            nv.push_back(1);
            ans.push_back(nv);
            v = nv;
        }
        return ans;
    }
};