/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopy(Node* head){
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            Node* nextElem = temp->next;
            temp->next = newNode;
            newNode->next = nextElem;
            temp=nextElem;
        }
    }
    void createRandom(Node* head){
        Node* temp = head;
        while(temp){
            Node* copyNode = temp->next;
            if(temp->random){
                 copyNode->random = temp->random->next;
            }else{
                copyNode->random = NULL;
            }
                temp = temp->next->next;
        }
    }
    Node* createCopy(Node* head){
        Node* temp = head;
        Node* dummyHead = new Node(-1);
        Node* res = dummyHead;
        while(temp){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyHead->next;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        insertCopy(head);
        createRandom(head);
        return createCopy(head);

    }
};