class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()){
            return 0;
        }
        int count = 0;
        

        vector<int> prefix_sum = {0};
        for (auto num : nums){
            int prev = prefix_sum.back();
            prefix_sum.push_back(num + prev);
        }

        int n = prefix_sum.size();


        for (int i = 0 ; i < n ;i++){
            int c = 0 ;

            while (c < i){
                if (prefix_sum[i] - prefix_sum[c] == k){
                    count++;
                }
                
                c++; 
            }
        }


        return count;
        
    }
};