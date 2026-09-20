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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // since the tree is a binary search tree, we can start from the root and go down until p and q bellong into two differents part
        // until we are on a node with p < node < q
        // that node is the lowest common ancestor

        if (root == nullptr) return nullptr; // should never happend

        if ((q->val <= root->val && root->val <= p->val) || (p->val <= root->val && root->val <= q->val)) return root;
        
        if (q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);


    }
};
