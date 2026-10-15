class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int> prefix(n);
       unordered_map<int , int> seen;
        seen.insert({0 , -1});
       int odd = 0;
       int res = 0;

       for (int i = 0 ; i < n ; i++){
            if (nums[i] % 2 == 1){
                odd++;
            }
            if (seen.count(odd) == 0){
                seen[odd] = i;
            }
            prefix[i] = odd;
       }

       for (int i = 0 ; i < n ; i++){
            if (prefix[i] < k) continue;

            int diff = prefix[i] - k;
            int lookup = diff + 1;

            res += seen[lookup] - seen[diff];
       }

       return res;

    }
};