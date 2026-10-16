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
    int pathSum(TreeNode* root, int targetSum) {

        /*
        for each node we can decide to choose it or not 
        */
        unordered_map<long, long> freq;
        int res = 0;
        freq[0] = 1;
        auto dfs = [&](auto&& self ,TreeNode* node , long long sum)->void{
            if (node == nullptr){
                return;
            }
        
            sum += node->val;

            long long diff = sum - targetSum;

            if (freq.count(diff)){
                res += freq[diff];
            }

            freq[sum]++;

            self(self , node->left , sum);
            self(self , node->right , sum);

            freq[sum]--;
            if (freq[sum] == 0) {
                freq.erase(sum);
            }
        };

        dfs(dfs , root , 0);

        return res;
        
    }
};