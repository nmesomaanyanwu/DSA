class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin() , strs.end());
        string ans = "";
        int n = strs.size();

        if (strs.size() == 1) return strs[0];
        ans = strs[0];

        for (int i = 1 ; i < n ; i++){
            string cur = strs[i];

            int j = 0;

            while (j < cur.size()){
                if (ans[j] == cur[j]){
                    j++;
                    continue;
                }
                else{
                    ans = ans.substr(0 , j);
                    break;
                }
            }

        }


        return ans;

        
    }
};