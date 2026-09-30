class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        /*Ok so lets see how do we do this ill do it bfs style */
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>> moves = {{1, 0}, {-1 , 0}, {0 , 1}, {0 , -1}, {1 , 1}, {1 , -1}, {-1 ,1}, {-1 ,-1}};

        vector<vector<int>> visited(rows , vector<int>(cols , 0));
        queue<vector<int>> pq;

        if (grid[0][0] == 1|| grid[rows -1][cols -1] == 1) return -1;

        pq.push({0 , 0 ,1});
        visited[0][0] = 1;


        while (!pq.empty()){
            vector<int> cur = pq.front();
            int r = cur[0];
            int c = cur[1];
            int l = cur[2];
            pq.pop();

            if (r == rows - 1 && c == cols -1) return l;

            for (auto [v , h] : moves){
                int nr = r + v;
                int nc = c + h;

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                if (grid[nr][nc] == 1) continue;

                if (visited[nr][nc] == 1) continue;

                pq.push({nr , nc , l + 1});
                visited[nr][nc] = 1;

            }
            
        }

        
        return -1;


    }
};