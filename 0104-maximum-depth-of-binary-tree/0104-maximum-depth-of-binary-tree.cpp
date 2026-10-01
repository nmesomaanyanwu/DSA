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
    int maxDepth(TreeNode* root) {
        /*ok so basically 
        1) we check if the root is null   and we return nullptr
        2) we look at the left and right sides , and returnn which will give  the max + 1*/

        if (root == nullptr) return 0;

        int left =  maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left , right);
    }
};