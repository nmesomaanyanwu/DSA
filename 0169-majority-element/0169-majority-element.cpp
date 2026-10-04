class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        int count = 0;

        for (int i = 0 ; i < n ; ++i){

            if (count == 0) res = nums[i];

            if (res == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }

        return res;
    }
};