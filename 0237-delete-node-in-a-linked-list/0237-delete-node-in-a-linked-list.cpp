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
    void deleteNode(ListNode* node) {
        ListNode* curr=node;
        ListNode* prev=node;

        while(curr && curr->next){
            swap(curr->val,curr->next->val);
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        delete(curr);
    }
};