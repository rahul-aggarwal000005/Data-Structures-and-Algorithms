/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool found = false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                found = true;
                break;
            }
        }
        if(!found){
            return NULL;
        }
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};