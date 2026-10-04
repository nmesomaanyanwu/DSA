class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , 0);

        for (int i = 0 ; i < n ; i++){

            if (i == 0){
                ans[i] = nums[i];
            }
            else{
                ans[i] = nums[i] + ans[i-1];
            }
        }
        return ans;
        
    }
};