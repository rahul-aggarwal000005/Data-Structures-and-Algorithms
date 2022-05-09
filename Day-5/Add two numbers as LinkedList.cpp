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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *res = new ListNode(-1);
        ListNode *tail = res;
        while(l1 != NULL and l2 != NULL){
            int sum = l1->val + l2->val + carry;
            int v = sum %10;
            carry = sum / 10;
            tail->next = new ListNode(v);
            l1 = l1->next;
            l2 = l2->next;
            tail = tail->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            int v = sum %10;
            carry = sum / 10;
            tail->next = new ListNode(v);
            l1 = l1->next;
            tail = tail->next;
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            int v = sum %10;
            carry = sum / 10;
            tail->next = new ListNode(v);
            l2 = l2->next;
            tail = tail->next;
        }
        if(carry){
            tail->next = new ListNode(1);
        }
        return res->next;
    }
};