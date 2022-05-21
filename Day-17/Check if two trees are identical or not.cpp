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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q != NULL) return false;
        if(q == NULL and p != NULL) return false;
        if(q == NULL and p == NULL) return true;
        bool lst = isSameTree(p->left,q->left);
        bool rst = isSameTree(p->right,q->right);
        return lst && rst && p->val == q->val;
    }
};