class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        tbh  for me on this question there is literally only the hashmap and prefix sum way of doing it 
        */
        int n = nums.size();
        unordered_map<int , int> seen; // these are the prefix sums
        vector<int> prefix_sum(n);
        seen.insert({0 , 1});

        for (int i = 0 ; i < n ; i++){
            if (i == 0){
                prefix_sum[i] = nums[i];
                continue;
            }

            prefix_sum[i] = nums[i]+ prefix_sum[i-1];
        }

        int count = 0;


        for (int i = 0 ; i < prefix_sum.size(); i++){
            int diff = prefix_sum[i] - k;
            if (seen.count(diff)){
                count += seen[diff];
            }
            seen[prefix_sum[i]]++;
        }

        //1 2 3  
        return count;

        
    }
};