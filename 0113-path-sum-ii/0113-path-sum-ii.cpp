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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](auto&& self , TreeNode* startNode , vector<int>& path , int count)-> void{
            if (startNode == nullptr) return ;
            path.push_back(startNode->val);

            if (startNode->left == nullptr && startNode->right == nullptr && count + startNode->val == targetSum){
                ans.push_back(path);
            }
            

            self(self , startNode->left , path , count+ startNode->val);

            self(self , startNode->right , path , count+ startNode->val);

            path.pop_back();

            return;

        };

        dfs(dfs , root , path , 0);

        return ans;
        
    }
};