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
    bool isSymmetric(TreeNode* root) {

        queue<pair<TreeNode* , TreeNode*>> q;
        q.push({root->left , root->right});

        while(!q.empty()){
            auto [l , r] = q.front();
            q.pop();

            if (l == nullptr && r == nullptr) continue;

            if (r == nullptr || l == nullptr) return false;

            if (l->val != r->val) return false;

            q.push({l->left , r->right}); 
            q.push({r->left , l->right}); 

        }
        return true;
        
    }
};