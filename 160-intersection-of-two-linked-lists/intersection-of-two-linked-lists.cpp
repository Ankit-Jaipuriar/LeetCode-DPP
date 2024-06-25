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
    int getlen(ListNode* head){
        int len=1;
        ListNode* curr = head;
        while(curr){
            len++;
            curr=curr->next;
        }
        return len;
    }
    ListNode* find(ListNode *headA, ListNode *headB, int k){
        ListNode* curr = headA;
        while(k--){
            curr = curr->next;
        }
        while(curr!=NULL && headB!=NULL){
            if(headB==curr){
                break;
            }
            curr=curr->next;
            headB = headB->next;
        }
        return curr;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int k = getlen(headA);
        int q = getlen(headB);
        int s = 0;
        ListNode* intersect_node;
        if(headA==headB){
            intersect_node = headB;
        }
        else if(k>q){
            s=(k-q);
            intersect_node = find(headA, headB, s);
        }else{
            s=(q-k);
             intersect_node = find(headB, headA, s);
        }
        return intersect_node;
    }
};