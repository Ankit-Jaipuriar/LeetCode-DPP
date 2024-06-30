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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nxt  = NULL;
        while(temp){
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* mid = getMiddle(head);
        ListNode* headnxt = reverse(mid->next);
        mid->next = NULL;
        ListNode* temp1 = head;
        ListNode* temp2 = headnxt;
        while(temp2){
            ListNode* nxtNode = temp1->next;
            temp1->next = temp2;
            temp2 = temp2->next;
            temp1->next->next = nxtNode;
            temp1 = nxtNode;
        }
    }
};