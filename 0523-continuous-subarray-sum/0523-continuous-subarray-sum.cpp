class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> seen; // keep the first index of the remainder
        seen.insert({0,-1});
        vector<int> prefix(n);


        for (int i = 0 ; i < n ; i++){
            if (i == 0){
                prefix[i] = nums[i];
            }
            else{
                prefix[i] = nums[i] + prefix[i-1];
            }
        }

        for (int i = 0 ; i < n ; i++){
            int diff = prefix[i] % k;

            if (seen.count(diff) == 0){
                seen[diff] = i;
            }
            else{
                if (i - seen[diff] >= 2){
                    return true;
                }
            }

        }

        return false;
        
    }
};