class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int a = 2*n; 
        vector<int> ans(a);

        for (int i = 0 ; i < n; i++){
            ans[i] = nums[i];
            ans[n+i] = nums[i];
        }

        return ans;
    }
};