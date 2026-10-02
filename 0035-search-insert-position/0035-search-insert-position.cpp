class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
        1) So its sorted 
        2) so we have the l and r pointers 
        3) What we do is that  we make the mid point
        4) if the mid point is too big for the target we move the lft pointer past the mid 
        5)else if its too small we move right 
        6) so its either that 
        */


        int l  = 0;
        int r = nums.size() - 1;

        while (l <= r){
            // get the mid point
            int m = (r + l) / 2;

            if (nums[m] == target) return m;
            else if (nums[m] < target) ++l;
            else if (nums[m] > target) --r;

        }


        return r+1;


        
    }
};