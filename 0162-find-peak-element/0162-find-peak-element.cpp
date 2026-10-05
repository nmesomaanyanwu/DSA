class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
        what im thinking is that  we binary search  on each side 
        1) if or mid num  is  grester than both the left and righ we return the mid index 
        2) else if its greater than 1 but less than the other go the that direction
        3) if its less than boh betwene the nums choose the one thats bigger 
        */
        int n = nums.size();

        int l = 0;
        int r = n -1;

        while(l <= r){
            int m = (l + r) / 2;

            if (m > 0 && (nums[m] < nums[m -1])){
                r = m -1;
            }
            else if ((m < n -1) && (nums[m] < nums[m + 1])){
                l = m + 1;
            }
            else {
                return m;
            }

        }

        return 0;
        

    }
};