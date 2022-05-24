/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL) return root;
        
        vector<vector<Node*>> ans;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<Node*> arr;
        while(!q.empty()){
            
            Node *node = q.front();
            q.pop();
            if(node == NULL){
                arr.push_back(NULL);
                ans.push_back(arr);
                arr.resize(0);
                if(q.size() > 0){
                    q.push(NULL);
                }
            }
            else{
                arr.push_back(node);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size()-1;j++){
                Node *node = ans[i][j];
                node->next = ans[i][j+1];
            }
        }
        
        return root;
    }
};