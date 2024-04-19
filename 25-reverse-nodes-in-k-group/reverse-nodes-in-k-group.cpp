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
    int getLength(ListNode* head){
        int len = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            curr = curr->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num = getLength(head);
        if(num<k){
            return head;
        }
        int x = k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int count = 0;
        while(x--){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if(forward!=NULL){
            head->next = reverseKGroup(forward, k);
        }
        return prev;
    }
};