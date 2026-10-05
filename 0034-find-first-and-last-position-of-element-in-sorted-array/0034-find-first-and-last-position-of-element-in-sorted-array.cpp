class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        Ok we are going to do 2 binary searches 
        1) we will do one to get the last most position where we will keep where we move the left pointer 
        2) one to get the strat most position where we move the right pointer
        */

        int first = -1;
        int last = -1;
        int n = nums.size();

        int l = 0;
        int r = n -1;

        while (l <= r){ // find the first occurence 
            int m = (l + r) / 2;

            if (nums[m] == target){
                first = m;
                r = m -1;
            }
            else if (nums[m] < target){
                l = m + 1;
            }
            else{
                r = m - 1;
            }

        }

        l = 0;
        r = n - 1;

        while (l <= r){
            // find the last occurence 
            int m = (l + r) / 2;

            if (nums[m] == target){
                last = m;
                l = m + 1;
            }
            else if (nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }

        }


        return {first , last};
    
        
    }
};