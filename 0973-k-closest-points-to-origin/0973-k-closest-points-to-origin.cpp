class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        auto cmp = [] (const pair<int , int>& a , const pair<int, int>& b){
            return ((a.first* a.first) + (a.second* a.second)) > ((b.first*b.first) + (b.second * b.second));
        };

        priority_queue<pair<int,int> ,vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for (int i = 0 ; i < points.size(); i++){
            vector<int> cur = points[i];
            pq.push({cur[0], cur[1]});
        }

        // next is this we return the k
        int n = min((int)pq.size() , k);

        for (int i = 0 ; i < n ; i++){
            auto cur = pq.top();
            pq.pop();
            ans.push_back({cur.first, cur.second});
        } 

        return ans;
    }
};