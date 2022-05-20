/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class item{
public:
    int hr;
    int vr;
    TreeNode *node;
    item(int h,int v,TreeNode *n){
        hr = h;
        vr = v;
        node = n;
    }
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int left = 0;
        int right = 0;
        queue<item> q;
        q.push({0,0,root});
        map<int,map<int,multiset<int>>> mp;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            TreeNode *node = cur.node;
            mp[cur.hr][cur.vr].insert(node->val);
            if(node->left){
                q.push({cur.hr-1,cur.vr+1,node->left});
            }
            if(node->right){
                q.push({cur.hr+1,cur.vr + 1,node->right});
            }
        }
        vector<vector<int>> res;
        for(auto x:mp){
            // cout<<x.first<<": ";
            vector<int> v;
            for(auto val:mp[x.first]){
                for(auto t:val.second){
                    v.push_back(t);
                }
            }
            res.push_back(v);
        }
    
        return res;
    }
};