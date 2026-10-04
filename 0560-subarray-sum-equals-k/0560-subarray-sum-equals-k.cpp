class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        ok lets try the prefix sum 
        so we will have a prefix sum vector and then  what will happen is that 
        1) We will keep a hashmap to store are prefix sums  and their count this will basially show how many times we can get a total of a praticular number by taking the full sum from the beginniing
        2) We wull then iterate through our loop if we see that are current minus k equals a prefix sum that exists we add it to our loop
        */
        int n = nums.size();
        unordered_map<int , int> count;
        count.insert({0 , 1});
        vector<int> prefix(n);
        int ans = 0;

        for (int i = 0 ; i < n ; i++){

            if (i == 0){
                prefix[i] = nums[i];
            }
            else{
                prefix[i] = nums[i] + prefix[i-1];
            }
        }

        // now  we go through the prefix sum and check 
        for (int i = 0 ; i < prefix.size(); i++){
            int sum = prefix[i] - k;

            if (count.count(sum) == 1){
                ans += count[sum];
            }
            // if its not equal we put this prefix in the hashmap

            count[prefix[i]]++;            
        }

        return ans;
    }
};