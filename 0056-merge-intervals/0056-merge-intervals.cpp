class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merges;

        sort(intervals.begin(), intervals.end());


        for (int i = 0 ; i < n ; i++){
            vector<int> cur = intervals[i];

            if (merges.empty()){
                merges.push_back({cur[0], cur[1]});
            }
            else{
                vector<int> last = merges.back();

                if ((last[0] <= cur[0]) && (last[1] >= cur[0]) && (last[1] <= cur[1])){
                    vector<int> new_bound = {last[0], cur[1]};
                    merges.pop_back();
                    merges.push_back(new_bound);
                }
                else if ((last[0] <= cur[0])&& (last[1] >= cur[1])){
                    continue;
                }
                else{
                    merges.push_back({cur[0], cur[1]});

                }
            }
            

        } 

        return merges;
        
    }
};