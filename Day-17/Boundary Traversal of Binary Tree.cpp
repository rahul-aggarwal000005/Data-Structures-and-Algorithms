/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> ans;

void leftPart(TreeNode<int>* root){
	if(root == NULL) return;
	if(root->left){
		ans.push_back(root->data);
		leftPart(root->left);
	}
	else if(root->right){
		ans.push_back(root->data);
		leftPart(root->right);
	}
}
void rightPart(TreeNode<int>* root){
	if(root == NULL) return;
	if(root->right){
		rightPart(root->right);
		ans.push_back(root->data);
	}
	else if(root->left){
		rightPart(root->left);
		ans.push_back(root->data);
	}
}
void leafs(TreeNode<int>* root){
	if(root == NULL) return;
	leafs(root->left);
	if(root->left == NULL and root->right == NULL){
		ans.push_back(root->data);
	}
	leafs(root->right);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
	ans.clear();
	ans.push_back(root->data);
	leftPart(root->left);
	leafs(root->left);
	leafs(root->right);
	rightPart(root->right);
	return ans;
}