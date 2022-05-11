/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node *cur = new Node(-1);
        Node *tail = cur;
        Node *temp = head;
        while(temp != NULL){
            tail->next = new Node(temp->val);
            tail = tail->next;
            mp[temp] = tail;
            temp = temp->next;
        }
        cur = cur->next;
        tail = cur;
        temp = head;
        while(temp != NULL){
            if(temp->random){
                tail->random = mp[temp->random];
            }
            tail = tail->next;
            temp = temp->next;
        }
        return cur;
    }
};