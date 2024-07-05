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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 2;
        ListNode* temp = head;
        vector<int> ans;
        if(head==NULL){
            return {-1,-1};
        }
        if(head->next->next==NULL || head->next==NULL){
            return {-1,-1};
        };
        bool flag = true;
        int cnt = 0;
        map<int,int> mp;
        ListNode* prevNode = temp->next;
        int store = prevNode->val;
        if(temp->val > store && prevNode->next->val>store){
                mp[i]=store;
         }
        else if(temp->val < store && prevNode->next->val<store){
                mp[i]=store;
         }
         temp = temp->next->next;
         i+=1;
        while(temp && temp->next){
        store = temp->val;
        if(prevNode->val > store && temp->next->val>store){
                mp[i]=store;
         }
        else if(prevNode->val < store && temp->next->val<store){
                mp[i]=store;
         }
            i++;
            prevNode = prevNode->next;
            temp = temp->next;
        }
        if(mp.empty() || mp.size()==1){
            return {-1,-1};
        }
        vector<int> idx;
        for(auto it:mp){
            idx.push_back(it.first);
        }
    int n  = idx.size();
    sort(idx.begin(), idx.end());
    int mini = INT_MAX;
    int maxi = idx[n-1] - idx[0];

    for (int i = 1; i < n; i++) {
        int diff = idx[i] - idx[i-1];
        mini = min(mini, diff);
    }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
        }
};