/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL, *cur = head, *nxt = NULL;
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *nhead = head;
        int cnt = 1;
        ListNode *temp = head;
        ListNode *prev = temp;
        while(cnt < k and temp != NULL){
            temp = temp->next;
            cnt++;
        }
        if(cnt == k){
            if(temp != NULL){
                ListNode *rem = reverseKGroup(temp->next,k);
                temp->next = NULL;
                head = reverse(head);
                temp = head;
                while(temp->next != NULL) temp = temp->next;
                temp->next = rem;
            }
            return head;
        }
        else{
            return nhead;
        }
    }
};