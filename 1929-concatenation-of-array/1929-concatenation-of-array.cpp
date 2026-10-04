class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> copy = nums;

        nums.insert(nums.end() , copy.begin() , copy.end());

        return nums;
    }
};