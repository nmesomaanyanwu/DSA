class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /* How im gonna solve this recurive problem firstly we have n 
        1) our base case for return or when a path is valid id when path is n* 2
        3) we have to make sure open < n and close runs when close < open
        */
        vector<string> ans;
        string path;


        auto dfs = [&](auto&& self , int open , int close)->void{

            if (path.size() == n* 2){
                ans.push_back(path);
                return;
            }

            if (open < n){
                path.push_back('(');
                self(self , open + 1 , close);
                path.pop_back();
            }

            if (close < open){
                path.push_back(')');
                self(self , open , close + 1);
                path.pop_back();
            }

        };

        dfs(dfs , 0 , 0);
        return ans;


    }
};