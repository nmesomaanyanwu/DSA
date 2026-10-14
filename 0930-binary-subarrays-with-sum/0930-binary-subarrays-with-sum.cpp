class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        /*Literaly the same as the previous example we can sliding window , prefix sum etc */
        int n = nums.size();
        unordered_map<int , int> seen;
        seen.insert({0 , 1});
        vector<int> prefix(n);

        for (int i = 0 ; i < n ; i++){
            if (i == 0){
                prefix[i] = nums[i];
            }
            else{
                prefix[i] = nums[i] + prefix[i - 1];
            }
        }
        int count = 0;

        for (int i = 0 ; i < prefix.size(); i++){
            int diff = prefix[i] - goal;

            if (seen.count(diff)){
                count += seen[diff];
            }
            
            seen[prefix[i]]++;
        }

        return count;


    }
};