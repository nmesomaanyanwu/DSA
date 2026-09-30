class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
        ill do all the 4 ways i can do this question firstly recursion , bfs , stack and then union find 
        */
        int rows = grid.size();
        int cols = grid[0].size();
        int max_count = 0;

        vector<pair<int , int>> moves = {{1,0}, {0, 1}, {-1,0}, {0 ,-1}}; 
        vector<vector<int>> visited(rows , vector<int>(cols , 0));

        auto dfs = [&] (auto&& self , int row , int col) -> int{

            if (visited[row][col] == 1) return 0;

            if (grid[row][col] == '0') return 0;

            visited[row][col] = 1;

            for (auto [v , h] : moves){
                int nr = v + row;
                int nc = h + col;

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols ) continue; 

                self(self , nr , nc);

            }


            return 1;

        };


        

        for (int r = 0 ; r < rows ; ++r){
            for (int c = 0 ; c < cols ; ++c){
                // so then we check in the grid for a char 
                if (grid[r][c] == '1')
                    max_count += dfs(dfs , r , c);
            }
        }

        return max_count;
        
    }
};