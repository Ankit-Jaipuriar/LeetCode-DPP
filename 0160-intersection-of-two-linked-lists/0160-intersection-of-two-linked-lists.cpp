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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //first approach
        //count len of both the linkedlist
        //find diff
        //move longer LL till diff
        //then start both the pointer of LL parallely

        //second approach
        //start traversing both together, then whenever pointer reaches to null, put it to other LL head.


        ListNode* a = headA;
        ListNode* b = headB;

        while(a!=b){
            if(a==NULL){
                a=headB;
            }else{
                a=a->next;
            }


            if(b==NULL){
                b=headA;
            }else{
                b=b->next;
            }
        }
    return a;
    }
};