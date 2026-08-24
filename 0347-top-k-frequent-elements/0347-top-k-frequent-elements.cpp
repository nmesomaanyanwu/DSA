#include <unordered_map>
#include <queue>
#include <utility>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> count;
        vector<int> ans;

        auto cmp = [](const vector<int>& a , const vector<int>& b){
            return a[1] < b[1]; // this means frequency will be what matters here its a max heap
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> hp(cmp);



        for (auto num : nums){
            count[num]++;
        }

        for (auto [key, value] : count){
            hp.push({key , value});
        }
        
        int n = min((int)hp.size(), k);

        for (int i = 0 ; i < n; i++){
            vector<int> cur = hp.top();
            hp.pop();
            ans.push_back(cur[0]);
        }


        return ans;

    }

};



