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
#define ll unsigned long long int
class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<ll,TreeNode*>> q;
        q.push({0,root});
        ll ans = 0;
        while(!q.empty()){
            ll sz = q.size();
            ll l = q.front().first;
            ll r = l;
            for(int i=0;i<sz;i++){
                auto cur = q.front(); q.pop();
                TreeNode *node = cur.second;
                r = cur.first;
                if(node->left){
                    q.push({2*r + 1,node->left});
                }
                if(node->right){
                    q.push({2*r+2,node->right});
                }
            }
            
            ans = max(ans,r - l + 1);
        }
        return ans;
    }
};