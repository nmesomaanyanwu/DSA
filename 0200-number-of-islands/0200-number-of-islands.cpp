class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;
        vector<pair<int ,int>> moves = {{1,0}, {-1, 0}, {0,1}, {0 , -1}};

        // make a function that if visted sets the iland 1 to 0  

        auto dfs = [&](auto&& self ,int row , int col)-> void{
            if (grid[row][col] == '0'){
                return ;
            }

            grid[row][col] = '0';

            for (auto [v , h] : moves){
                int nr = row + v;
                int nc = col + h;

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols){
                    continue;
                }

                if (grid[nr][nc] == '0'){
                    continue;
                }

                self(self , nr, nc);
            }
        };

        for (int r = 0 ; r < rows; r++){
            for (int c = 0 ; c < cols ; c++){
                if (grid[r][c] == '1'){
                    count++;
                    dfs(dfs, r , c);
                    
                }
            }
        }
        
        return count;
    }
};