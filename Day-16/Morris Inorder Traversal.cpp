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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        vector<int> res;
        while(cur != NULL){
            if(!cur->left){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode *pre = cur->left;
                while(pre->right != NULL and pre->right != cur){
                    pre = pre->right;
                }
                if(!pre->right){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};