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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* getKthnode(ListNode* curr, int k) {
        k -= 1;
        while (curr != NULL && k > 0) {
            k--;
            curr = curr->next;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prevLast = NULL;
        ListNode* newHead = NULL;

        while (curr) {
            ListNode* kthnode = getKthnode(curr, k);
            if (kthnode == NULL) {
                if (prevLast) {
                    prevLast->next = curr;
                }
                break;
            }

            ListNode* nextNode = kthnode->next;
            kthnode->next = NULL;
            ListNode* reversedHead = reverse(curr);

            if (newHead == NULL) {
                newHead = reversedHead;
            }

            if (prevLast) {
                prevLast->next = reversedHead;
            }
            prevLast = curr;
            curr = nextNode;
        }

        return newHead ? newHead : head;
    }
};
