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
    int length(ListNode *head){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        if(len == 0) return head;
        k = k%len;
        ListNode *prev = NULL, *cur = head;
        if(k == 0) return head;
        for(int i=0;i<len-k;i++){
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        ListNode *temp = cur;
        while(temp->next != NULL) temp = temp->next;
        temp->next = head;
        return cur;
        
    }
};