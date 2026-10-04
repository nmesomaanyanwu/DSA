class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int last = nums[n-1];
        int start = nums[0];

        unordered_set<int> d(nums.begin() , nums.end());

        for (int i = start + 1 ; i < last ; i++){
            if (d.count(i) == 0){
                ans.push_back(i);
            }
        }

        return ans;
    
         
    }
};