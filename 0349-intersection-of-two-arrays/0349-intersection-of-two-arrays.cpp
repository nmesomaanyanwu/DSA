class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
       

        unordered_set<int> seen1(nums1.begin() , nums1.end());
        unordered_set<int> seen2(nums2.begin() , nums2.end());


        for (auto n : seen1){
            if (seen2.count(n) == 1){
                ans.push_back(n);
            }
        }


        return ans;

        
    }
};