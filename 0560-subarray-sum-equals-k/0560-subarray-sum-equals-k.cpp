class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()){
        return 0;
        }

        unordered_map<int , int> freq = {{0, 1}};

    
        int prefix_sum = 0;
        int count = 0;

        for (auto num : nums){
            prefix_sum += num;

            int needed = prefix_sum - k;

            if (freq.count(needed) == 1){
                count += freq[needed];
            }

            freq[prefix_sum]++;
        }

        return count;
    }
};