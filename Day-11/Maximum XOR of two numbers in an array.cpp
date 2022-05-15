class Node{
public:
    Node *zbit;
    Node *obit;
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
    
    int findMaximumXOR(vector<int>& nums) {
        Node *root = new Node();
        for(auto x:nums){
            insert(root,x);
        }
        int ans = -1;
        for(auto x:nums){
            ans = max(ans,maxXOR(root,x));
        }
        return ans;
    }
};