class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        /*Literaly the same as the previous example we can sliding window , prefix sum etc */
        
        auto helper = [&](auto&& self , int x) -> int{
            if (x == -1) return 0;
            int l = 0;
            int cur = 0;
            int res = 0;

            for (int r = 0 ; r < nums.size() ; r++){
                cur += nums[r];

                while(cur > x){
                    cur -= nums[l];
                    l++;
                }

                res += (r - l) + 1;
            }
            return res;
        };


        return helper(helper, goal) - helper(helper , goal - 1);

    }
};