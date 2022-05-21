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
    pair<int,int> call(TreeNode *root){
        if(root == NULL) return {0,0};
        
        pair<int,int> lst = call(root->left);
        pair<int,int> rst = call(root->right);
        
        int h = max(lst.second,rst.second) + 1;
        int d = max({lst.first,rst.first,lst.second + rst.second});
        return {d,h};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = call(root);
        return ans.first;
    }
};