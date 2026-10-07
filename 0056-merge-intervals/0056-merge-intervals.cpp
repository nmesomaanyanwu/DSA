class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (intervals.empty()) return {};

        vector<vector<int>> merges;

        sort(intervals.begin(), intervals.end());

        merges.push_back({intervals[0][0],intervals[0][1]});

        for (int i = 1 ; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            vector<int> prev = merges.back();

            if (start > prev[1]){
                merges.push_back({start , end});
            }
            else{
                merges.pop_back();
                start = min(prev[0], start);
                end = max(prev[1], end);

                merges.push_back({start , end});
            }
            
        } 

        return merges;
        
    }
};