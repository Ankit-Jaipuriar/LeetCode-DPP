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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr!=NULL){
            int a = gcd(prev->val,curr->val);
            ListNode* newNode = new ListNode(a);
            prev->next = newNode;
            newNode->next = curr;
            curr=curr->next;
            if(prev->next->next!=NULL){
            prev=prev->next->next;
            }
        }
        return head;
    }
};