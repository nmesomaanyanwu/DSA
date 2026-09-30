class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*How am i gonna solve this question 
        1) il put every rotten orange so far on the queue
        2) then if theres a fres orange 4 dimesnsionally from it ill turn it to a rotten orrange 
        3) if we have a 2 we skipp it dont add it that means its been seen  also 0 doesnt matter 
        4) if there are still ones at the end we return -1
        */
        int rows = grid.size();
        int cols  = grid[0].size();
        vector<pair<int , int>> moves = {{1 , 0} , {0 , 1}, {-1, 0}, {0 , -1}};
        int max_num = 0;

        // lets have a queue that win take in the coordinates of an orange and also the minute 
        queue<vector<int>> q;

        // we have cols and rows 
        for (int r = 0 ; r < rows ; ++r){
            for (int c = 0 ; c < cols ; ++c){
                if (grid[r][c] == 2) q.push({r , c , 0});
            }
        }



        while (!q.empty()){
            // we pop this our current r , c value 
            vector<int> cur = q.front();
            q.pop();
            int row = cur[0];
            int col = cur[1];
            int t = cur[2];
            // we then move to each of its neighbours
            // remove moves that are not possible or out of bounds 
            // we wouldnt want to push a rotten orange or 0 cell so we actually change it to 2 to mark as visited than push 
            max_num = max(max_num , t);

            for (auto [v , h] : moves){
                int nr = v + row;
                int nc = h + col;

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                if (grid[nr][nc] == 0 || grid[nr][nc] == 2) continue;

                grid[nr][nc] = 2;
                q.push({nr , nc , t + 1});
            }
        }

        // end check so we check if every thing is 2 or 0 else we return -1 
        for (int r = 0 ; r < rows ; ++r){
            for (int c = 0 ; c < cols ; ++c){
                // s o here its like 
                if (grid[r][c] == 1) return -1;
            }
        }

    
        return max_num;
        
    }
};