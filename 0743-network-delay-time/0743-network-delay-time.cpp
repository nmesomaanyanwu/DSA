class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
        1) make an adjacecy list of no to their  time and edges 
        2) then we addd the time of the source node to the destination node 
        3) we make take the max_count at each interval 
        */

        unordered_map<int , vector<pair<int, int>>> adj_list;

        for (int i = 0 ; i < times.size(); ++i){
            // source node is the key and the target node an dtime are values 
            vector<int> cur = times[i];
            adj_list[cur[0]].push_back({cur[2], cur[1]});
        }

        // make a min heap to be keeping the next best value 
        priority_queue<pair<int , int>, vector<pair<int , int>>, greater<>> min_heap;
        unordered_set<int> visited;
        int max_count = 0;

        min_heap.push({0 , k});
       

    

        while (!min_heap.empty()){
            auto [time , node] = min_heap.top();
            min_heap.pop();

            if (visited.count(node) == 1) continue;
            visited.insert(node);
          
            max_count = max(max_count , time);

            for (int i = 0 ; i < adj_list[node].size(); ++i){
                auto [t , nei] = adj_list[node][i];
                if ( visited.count(nei) == 1) continue;

                min_heap.push( {time + t, nei});
            }
        }

        if (visited.size() != n) return -1;
        else return max_count;
        
    }
};