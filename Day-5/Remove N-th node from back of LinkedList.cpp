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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        for(int i=0;i<n;i++){
           cur = cur->next;
        }
        
        ListNode *slow = head;
        while(cur != NULL){
            prev = slow;
            slow = slow->next;
            cur = cur->next;
        }
        if(prev == NULL){
            return head->next;
        }
        prev->next = slow->next;
        return head;
    }
};