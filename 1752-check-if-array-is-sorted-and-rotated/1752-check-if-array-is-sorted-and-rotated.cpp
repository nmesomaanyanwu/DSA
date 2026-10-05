class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());

        int i = 0;
        while (i < n){

            if (nums == sorted) return true;

            int val = nums.front();
            nums.push_back(val);
            nums.erase(nums.begin());
            i++;
        }

        return nums == sorted;
        


    }
};