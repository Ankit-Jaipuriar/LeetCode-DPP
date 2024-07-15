/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (auto i : descriptions) {
            int parentVal = i[0];
            int childVal = i[1];
            bool isLeft = i[2] == 1;

            if (mp.find(parentVal) == mp.end()) {
                mp[parentVal] = new TreeNode(parentVal);
            }
            if (mp.find(childVal) == mp.end()) {
                mp[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                mp[parentVal]->left = mp[childVal];
            } else {
                mp[parentVal]->right = mp[childVal];
            }

            children.insert(childVal);
        }

        TreeNode* root = nullptr;
        for (auto [val, node] : mp) {
            if (children.find(val) == children.end()) {
                root = node;
                break;
            }
        }

        return root;
    }
};
