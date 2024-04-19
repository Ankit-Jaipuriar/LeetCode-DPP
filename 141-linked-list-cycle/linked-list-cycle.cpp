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
    bool hasCycle(ListNode *head) {
        // if(head==NULL || head->next==NULL){
        //     return false;
        // }
        // ListNode* slow = head;
        // ListNode* fast = head;
        // while(fast!=NULL && slow!=NULL){
        //     fast = fast->next;
        //     if(fast!=NULL){
        //         fast = fast->next;
        //     }
        //     slow = slow->next;
        // if(fast == slow){
        //     return true;
        // }
        // }
        // return false;
        if(head==NULL){
            return NULL;
        }
        ListNode* temp = head;
        map<ListNode*, bool> visited;
        while(temp!=NULL){
            if(visited[temp]==true){
                return true;
            }
            visited[temp]=true;
            temp = temp->next;
        }
        return false;
    }
};