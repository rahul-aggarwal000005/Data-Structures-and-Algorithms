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
    int getLength(ListNode *head){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int d1 = getLength(headA);
        int d2 = getLength(headB);
        while(d1 < d2){
            headB = headB->next;
            d2--;
        }
        while(d1 > d2){
            headA = headA->next;
            d1--;
        }
        while(headA != NULL and headB != NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};