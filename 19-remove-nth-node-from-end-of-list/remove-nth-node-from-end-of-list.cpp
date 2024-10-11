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
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;
        int cnt=0;
        while(cnt<=n) {
            fast = fast->next;
            cnt++;
        }

        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);

        return dummyNode->next;
    }
};
