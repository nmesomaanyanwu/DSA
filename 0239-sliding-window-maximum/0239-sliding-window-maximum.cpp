class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> max_num; // {value, index}
        vector<int> res;
        int l = 0;

        for (int r = 0; r < k; r++) {
            max_num.push({nums[r], r});
        }
        res.push_back(max_num.top().first);

        for (int right = k; right < nums.size(); right++) {
            l++;
            max_num.push({nums[right], right});

            while (!max_num.empty() && max_num.top().second < l) {
                max_num.pop();
            }

            res.push_back(max_num.top().first);
        }

        return res;


        
    }
};