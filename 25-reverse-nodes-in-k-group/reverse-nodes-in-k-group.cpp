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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* getkthNode(ListNode* head, int k){
        k-=1;
        ListNode* temp = head;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp = head;
       ListNode* kthNode;
       ListNode* prevLast = NULL;
       while(temp){
        kthNode = getkthNode(temp,k);
        if(kthNode==NULL){
            if(prevLast){
            prevLast->next = temp;
            }
            break;
        }
        ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;
       reverse(temp);
        if(temp==head){
            head = kthNode;
        }else{
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
       }
       return head;
    }
};
