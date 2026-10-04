class Solution {
public:
    int missingInteger(vector<int>& nums) {
        /*
        what to do:
        firstly , get the longest sequential subarray 
        2) but all the elements in a set
        3) find the prefix sum of the longest sequential subarray
        4)from there check if it exists in the array if it does continue else retun that ans 
        */
        if (nums.size() == 1) return nums[0]+ 1;

        unordered_set<int> exists(nums.begin() , nums.end());
        
        int sum = nums[0];

        for (int i = 1 ; i < nums.size(); i++){
            if (nums[i] == (nums[i - 1] + 1)){
                sum += nums[i];
            }
            else{
                break;
            }
        }

        while (exists.count(sum)){
            sum++;
        }

        return sum;

    }
};