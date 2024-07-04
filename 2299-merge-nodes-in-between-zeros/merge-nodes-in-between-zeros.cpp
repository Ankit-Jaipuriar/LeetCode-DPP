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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* tempx = dummy;
        while(temp!=NULL){
            ListNode* t;
            int sum = 0;
            while(temp && temp->val!=0){
                sum+=temp->val;
                temp = temp->next;
         }
         if(temp!=NULL){
            temp = temp->next;
         }
         tempx->next =  new ListNode(sum);
         tempx = tempx->next;
        }
        return dummy->next;
    }
};