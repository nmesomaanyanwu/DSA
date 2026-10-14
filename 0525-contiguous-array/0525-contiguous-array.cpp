class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*
        so were gonna  use a hashmap to keep count of the minimum prefix difference at each index which we will need to get rid off to make our count equal 

        */
        unordered_map<int , int> prefix;
        int zeros = 0;
        int ones = 0;
        int res = 0;

        for (int i = 0 ; i < nums.size(); i++){
            if (nums[i] == 1){
                ones++;
            }
            else{
                zeros++;
            }

            int diff = ones - zeros;

            if (prefix.count(diff) == 0){
                prefix[diff] = i;
            }

            if (diff == 0){
                res = ones + zeros;
            }

            res = max(res , i - prefix[diff]);
        }

        return res;
        

    }
};