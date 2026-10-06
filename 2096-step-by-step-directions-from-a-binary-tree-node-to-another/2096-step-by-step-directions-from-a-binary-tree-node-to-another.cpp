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
    string getDirections(TreeNode* root, int startValue, int destValue) {
            /*
            Firstly we get the lowest common ancestor and then we check from the root 
            we do the directions 
            */

            // lets get the lowest common ancest 
            vector<string> Directions;

            auto lca = [](auto&& self,TreeNode* root, int p , int q)-> TreeNode*{
                if (root == nullptr || root->val == p || root->val == q) return root;

                TreeNode* left = self(self,root->left , p , q);
                TreeNode* right = self(self ,root->right , p , q);

                if (left != nullptr && right != nullptr) return root;

                if (left != nullptr) return left;

                return right;

            };

            TreeNode* n = lca(lca ,root , startValue, destValue);

            // now we check  how do we get the start value , we check if its on the left or right side and how long it took from 
            // 

            vector<char> startNode;
            vector<char> endNode;
           

            auto get = [&](auto&&self , TreeNode* root , int des , vector<char>& direction)-> bool{
                if (root == nullptr){
                    return false;
                }

                if (root->val == des){
                    return true;
                }

                direction.push_back('L');

                if (self(self, root->left , des, direction)){
                    return true;
                }
                
                direction.pop_back();

                direction.push_back('R');
                if (self(self, root->right , des, direction)){
                    return true;
                }
                direction.pop_back();

                return false;

            };

            get(get , n , startValue, startNode);
            get(get , n , destValue, endNode);

            string ans= "";

            for (int i = 0 ; i < startNode.size() ; i++){
                ans += "U";
            }

            for (int i = 0 ; i < endNode.size() ; i++){
                ans += endNode[i];
            }


            return ans;
                 
    }
};