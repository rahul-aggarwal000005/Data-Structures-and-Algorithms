/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> res;
 TreeNode *call(TreeNode *root,int b){
     if(root == NULL) return NULL;
     if(root->val == b){
         res.push_back(root->val);
         return root;
     }
     res.push_back(root->val);
     TreeNode *lst = call(root->left,b);
     if(lst != NULL) return lst;
     TreeNode *rst = call(root->right,b);
     if(rst != NULL) return rst;
     res.pop_back();
     return NULL;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    res.clear();
    call(A,B);
    return res;
}
