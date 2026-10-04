class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> left(n);
        vector<int> right(n);

        // firstly let fill the left with the product that came before it , the first element is a case where we put one because no element came before it

        for (int i = 0 ; i < nums.size(); i++){
            if (i == 0){
                left[i] = 1;
            }
            else{
                left[i] = nums[i-1] * left[i-1];
            }
        }

        // now right

        for (int i = n - 1 ; i >= 0 ; i--){
            if (i == n-1){
                right[i] = 1;
            }
            else{
                right[i] = nums[i+1] * right[i + 1];
            }
        }


        for (int i = 0 ; i < n ; i++){
            ans[i] = left[i] * right[i];
        }

        return ans;
        
    }
};