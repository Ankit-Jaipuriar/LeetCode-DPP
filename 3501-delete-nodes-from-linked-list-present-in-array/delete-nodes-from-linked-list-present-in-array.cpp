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
    // ListNode* helper(ListNode* head, int k){
    //     ListNode* dummy = new ListNode(-1);
    //     dummy->next = head;
    //     ListNode* prev = dummy;
    //     ListNode* temp = head;
    //     while(temp!=NULL){
    //         if(temp->val==k){
    //             prev->next = temp->next;
    //             delete temp;
    //             temp = prev->next;
    //         }else{
    //             prev = temp;
    //             temp = temp->next;
    //         }
    //     }
    //     return dummy->next;
    // }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         unordered_set<int> toRemove(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            if (toRemove.find(temp->val) != toRemove.end()) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        return dummy->next;
    }
};