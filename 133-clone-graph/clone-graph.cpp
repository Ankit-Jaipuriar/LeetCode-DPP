/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
        unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node* newNode = new Node(node->val);
        mp[node]=newNode;
        for(auto neighbor:node->neighbors)
        if(mp.find(neighbor)==mp.end()){
            (newNode->neighbors).push_back(cloneGraph(neighbor));
        }else{
            (newNode->neighbors).push_back(mp[neighbor]);
        }
        return newNode;
    }
};