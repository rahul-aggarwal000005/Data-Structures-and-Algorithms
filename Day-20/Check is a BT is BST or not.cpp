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
    bool helper(TreeNode *root,long long minVal,long long maxVal){
        if(root == NULL) return true;
        bool lst = helper(root->left,minVal,root->val);
        bool rst = helper(root->right,root->val,maxVal);
        if(root->val > minVal && root->val < maxVal && lst && rst) return true;
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long long minVal = -1e14;
        long long maxVal = 1e14;
        return helper(root,minVal,maxVal);
    }
};