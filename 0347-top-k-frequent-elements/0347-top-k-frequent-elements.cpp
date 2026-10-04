class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int , int> freq ; // for the frequency of digits 

        auto cmp = [](const pair<int, int>& a , const pair<int , int>& b){
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHp(cmp);

        for (int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
        }

        for (auto [key , val] : freq){
            maxHp.push({key , val});
        }

        while(k >0){
           ans.push_back(maxHp.top().first);
           maxHp.pop();
            k--;
        }

        return ans;
        
    }
};