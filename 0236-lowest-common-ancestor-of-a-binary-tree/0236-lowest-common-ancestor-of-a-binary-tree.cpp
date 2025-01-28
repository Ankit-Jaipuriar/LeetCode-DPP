/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> height; 
    void DFS(TreeNode* node, TreeNode* par) {
        if (!node) return;

        parent[node] = par; 
        height[node] = par ? height[par] + 1 : 0; 

        DFS(node->left, node);
        DFS(node->right, node);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        DFS(root, nullptr); 
        while (height[p] > height[q]) p = parent[p];
        while (height[q] > height[p]) q = parent[q];
        while (p != q) {
            p = parent[p];
            q = parent[q];
        }

        return p; 
    }
};