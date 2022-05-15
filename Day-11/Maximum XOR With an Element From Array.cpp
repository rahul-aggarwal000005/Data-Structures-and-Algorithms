class Node{
public:
    Node *zbit, *obit;
    Node(){
        zbit = NULL;
        obit = NULL;
    }
};
class Solution {
public:
    void insert(Node *&root,int val){
        Node *cur = root;
        for(int i=31;i>=0;i--){
            int mask = 1<<i;
            int bit = (mask & val);
            if(bit){
                if(!cur->obit) cur->obit = new Node();
                cur = cur->obit;
            }
            else{
                if(!cur->zbit) cur->zbit = new Node();
                cur = cur->zbit;
            }
        }
    }
    int maxXOR(Node *&root,int val){
        Node *cur = root;
        if(cur->obit == NULL and cur->zbit == NULL) return -1;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int mask = 1<<i;
            int bit = (mask & val);
            if(bit){
                if(cur->zbit != NULL){
                    ans += mask;
                    cur = cur->zbit;
                }
                else{
                    cur = cur->obit;
                }
            }
            else{
                if(cur->obit != NULL){
                    ans += mask;
                    cur = cur->obit;
                }
                else{
                    cur = cur->zbit;
                }
            }
        }   
        return ans;
    }
    
   
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Node *root = new Node();
        vector<vector<int>> v;
        int n = queries.size();
        for(int i=0;i<n;i++){
            v.push_back({queries[i][1],queries[i][0],i});
        }
        sort(v.begin(),v.end());
        sort(nums.begin(),nums.end());
        vector<int> res(n);
        int i = 0;
        for(auto x:v){
            while(i<nums.size() and x[0] >= nums[i]){
                insert(root,nums[i]);
                i++;
            }
            res[x[2]] = maxXOR(root,x[1]);
        }
        return res;
    }
};