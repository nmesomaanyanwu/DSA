class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*What im thinking 
        okay so we have a vector visited that will represent nodes we've seen and nodes we havent 
        We have moves in all 4 directions then we literally check for min count all the directions the ]
        thing can move each time it can move we add 1  then return the number 
        */
        int max_num = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows , vector<int>(cols , 0));
        vector<pair<int , int>> moves = {{1 ,0}, {0, 1}, {-1 , 0}, {0 , -1}}; 


        auto dfs = [&] (auto&& self , int row , int col) -> int {
            if (visited[row][col] == 1|| grid[row][col] == 0) return 0;

            visited[row][col] = 1;

            int size = 1;

            for (auto [v , h] : moves){
                int nr = v + row;
                int nc = h + col;

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                if (visited[nr][nc] == 1) continue;

                size += self(self , nr , nc);
            }
            

            return size;

        };

        for (int r = 0 ; r < rows ; ++r){
            for (int c = 0 ; c < cols ; ++c){

                if (grid[r][c] == 1){
                    max_num = max(max_num , dfs(dfs , r ,c));
                }
            }
        }

        return max_num;


    }
};