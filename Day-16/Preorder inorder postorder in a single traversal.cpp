/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
vector<int> pre,pos,in;
void call(BinaryTreeNode<int> *root){
	if(root == NULL) return;
	pre.push_back(root->data);
	call(root->left);
	in.push_back(root->data);
	call(root->right);
	pos.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
	pre.clear();
	pos.clear();
	in.clear();
	vector<vector<int>> res;
	call(root);
	res.push_back(in);
	res.push_back(pre);
	res.push_back(pos);
	return res;
}