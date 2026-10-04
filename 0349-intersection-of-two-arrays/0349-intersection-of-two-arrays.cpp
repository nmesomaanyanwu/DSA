class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> count1(1001, 0);
        

     

        for (int i = 0 ; i < nums1.size() ; i++){
            count1[nums1[i]]++;
        }
        
        for (int i = 0 ; i < nums2.size(); i++){
            if (count1[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                count1[nums2[i]] = 0;
            }
            
        }

        return ans;

         

        
    }
};