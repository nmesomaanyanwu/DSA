class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        How do i do bucket sort okay what ever 
        
        
        */
        int n = nums.size();
        unordered_map<int , int> freq;
        vector<vector<int>> bucket(n + 1);

        for (int i = 0 ; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        for (auto [no , count]: freq){
            bucket[count].push_back(no);
        }

        vector<int> ans;

        while(k > 0){
            vector<int> cur = bucket.back();
            bucket.pop_back();
            if (cur.empty()) continue;

            for (auto num : cur){
                ans.push_back(num);
                k--;
            }
           
            
        }

        return ans;
        
    }
};