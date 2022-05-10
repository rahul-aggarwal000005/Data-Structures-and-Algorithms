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
        ListNode *cur = head,*prev = NULL,*nxt;
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *l2 = reverse(slow->next);
        while(l2 != NULL and head != NULL){
            if(l2->val != head->val) return false;
            l2 = l2->next;
            head = head->next;
        }
        return true;
        
    }
};