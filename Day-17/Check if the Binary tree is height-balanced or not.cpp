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
    pair<int,int> helper(TreeNode *root){
        if(root == NULL){
            return {1,0};
        }
        pair<int,int> lst = helper(root->left);
        pair<int,int> rst = helper(root->right);
        int h = max(lst.second,rst.second) + 1;
        int b = (abs(lst.second - rst.second) <= 1) && lst.first && rst.first;
        return {b,h};
    }
    bool isBalanced(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return ans.first;
    }
};