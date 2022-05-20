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
    vector<int> res;
    void call(TreeNode *root){
        if(root == NULL) return;
        call(root->left);
        res.push_back(root->val);
        call(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
        call(root);
        return res;
    }
};