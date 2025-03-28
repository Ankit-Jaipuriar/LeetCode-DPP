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
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;

        int cnt=0;
        while(cnt<=n){
            fast=fast->next;
            cnt++;
        }

        while(fast){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* temp = slow->next;
        slow->next=slow->next->next;
        delete(temp);

        return dummy->next;
    }
};