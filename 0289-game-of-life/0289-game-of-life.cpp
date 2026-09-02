class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<pair<int , int>> moves = {{1, 0}, {-1, 0}, {0 , -1}, {0, 1},{1,1}, {-1 ,1},{-1,-1}, {1,-1}}; // these are our moves 


        vector<vector<int>> grid = board;


        auto dfs = [&](auto&& self , int row , int col)->void{
            int zeros= 0;
            int ones = 0;

            if (grid[row][col] == 1){

                for (auto [r , c] : moves){
                    int nr = row + r;
                    int nc = col + c;

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols){
                        continue;
                    }
                    if (grid[nr][nc] == 1){
                        ones++;
                    }
                    if (grid[nr][nc] == 0){
                        zeros++;
                    }
                }

                if (ones < 2){
                    board[row][col] = 0;
                }
                else if (ones > 3){
                    board[row][col] = 0; // over population
                }

            }
            else if (grid[row][col] == 0){

                for (auto [r , c] : moves){
                    int nr = row + r;
                    int nc = col + c;

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols){
                        continue;
                    }
                    if (grid[nr][nc] == 1){
                        ones++;
                    }
                    if (grid[nr][nc] == 0){
                        zeros++;
                    }
                }

                if (ones == 3){
                    board[row][col] = 1; // 
                }

            }
        };



        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols; j++){

                dfs(dfs, i, j);
            }
        }



        
    }
};