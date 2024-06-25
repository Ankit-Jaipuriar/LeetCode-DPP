class LRUCache {
public:
    struct node{
        int key, val;
        node *prev;
        node *next;
        node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    map<int, node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* resnode = mp[key];
            int ans = resnode->val;
            mp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mp[key] = head->next;
            return ans;
        }
        else return -1;
    }
    
    void put(int key, int val) {
        if(mp.find(key)!=mp.end()){
            node* existingnode = mp[key];
            mp.erase(key);
            deleteNode(existingnode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, val));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */