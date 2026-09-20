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
    vector<int> output;

    void buildOutput(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (output.size() < depth + 1) {
            output.push_back(root->val);
        } 
        if (root->right != nullptr) buildOutput(root->right, depth + 1);
        if (root->left != nullptr) buildOutput(root->left, depth + 1);

        
    }

public:
    vector<int> rightSideView(TreeNode* root) {

        // we can do a recursive thing
        // we need to do the recursion in the right order, and every time we do it we rewrite the value 
        // so the ending value will be the rightest one


        //if (root == nullptr) return {};
        output = {};

        buildOutput(root, 0);

        return output;

    }
};











