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
private: 
    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = depth(root->left);
        if (l == -1) return -1;
        int r = depth(root->right);
        if (r == -1) return -1;

        if (l - r > 1 or r - l > 1) {
            return -1;
        }

        else {
            return 1 + max(r,l);
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if (depth(root) != -1) {
            return true;
        } else {
            return false;
        }
    }
};
