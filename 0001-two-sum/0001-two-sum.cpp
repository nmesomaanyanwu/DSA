#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*firstly keep a map of nums weve seen if target - current is in map return the indices of that nand this*/
        map<int , int> seen;

        for (int i = 0 ; i < nums.size(); i++){
            int diff = target - nums[i];
            if (seen.count(diff) ==1){
                return {seen[diff], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};