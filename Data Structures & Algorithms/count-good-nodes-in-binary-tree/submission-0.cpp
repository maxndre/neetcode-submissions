int explore(TreeNode* node, int max) {
    if (node == nullptr) return 0;
    int x;

    if (node->val >= max) {
        x = 1;
        //cout << node->val << " >= " << max << "\n";
        }
    else x = 0;

    max =  std::max(max, node->val);

    return explore(node->left, max) + explore(node->right, max) + x;
    
    
}



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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        return explore(root, -100);
        
    }
};
