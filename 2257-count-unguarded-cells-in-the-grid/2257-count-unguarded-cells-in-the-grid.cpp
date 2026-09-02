class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        /*
            3 represents walls 
            0 represents free 
            1 represents guards 
            2 represents in guards site 
        */
        vector<vector<int>> grid(m , vector<int>(n , 0));

        for (int i = 0 ; i < walls.size() ; i++){
            int r = walls[i][0];
            int c = walls[i][1];

            grid[r][c] = 3;
        }

        for (int i = 0 ; i < guards.size() ; i++){
            int r = guards[i][0];
            int c = guards[i][1];

            grid[r][c] = 1;
        }
        vector<pair<int,int>> moves = {{1,0}, {-1, 0},{0,1}, {0,-1}};
        auto up = [&](auto&& self , int row ,int  col)-> void{
            if (row < 0 || row >= m || col < 0 || col >=n){
                return;
            }
            if (grid[row][col] == 3 || grid[row][col] == 1){
                return;
            }
            else if (grid[row][col] == 0){
                grid[row][col] = 2;
                self(self , row-1, col);
            }
            else if (grid[row][col] == 2){
                self(self , row-1, col);
            }
        };

         auto down = [&](auto&& self , int row ,int  col)-> void{
            if (row < 0 || row >= m || col < 0 || col >=n){
                return;
            }
            if (grid[row][col] == 3 || grid[row][col] == 1){
                return;
            }
            else if (grid[row][col] == 0){
                grid[row][col] = 2;
                self(self , row+1, col);
            }
            else if (grid[row][col] == 2){
                self(self , row+1, col);
            }
            
        };

        auto left = [&](auto&& self , int row ,int  col)-> void{
            if (row < 0 || row >= m || col < 0 || col >=n){
                return;
            }
            if (grid[row][col] == 3 || grid[row][col] == 1){
                return;
            }
            else if (grid[row][col] == 0){
                grid[row][col] = 2;
                self(self , row, col-1);
            }
            else if (grid[row][col] == 2){
                self(self , row, col -1);
            }
            
        };

        auto right = [&](auto&& self , int row ,int  col)-> void{
            if (row < 0 || row >= m || col < 0 || col >=n){
                return;
            }
            if (grid[row][col] == 3 || grid[row][col] == 1){
                return;
            }
            else if (grid[row][col] == 0){
                grid[row][col] = 2;
                self(self , row, col + 1);
            }
            else if (grid[row][col] == 2){
                self(self , row, col + 1);
            }
            
        };

        auto dfs = [&] (auto&& self , int row , int col)->void{
            up(up , row -1 , col);
            down(down , row + 1, col);
            left(left ,row , col -1);
            right(right, row , col + 1);


        };

        for (int r = 0 ; r < m; r++){
            for (int c = 0 ; c < n ; c++){
                
                if (grid[r][c] == 1){
                    dfs(dfs , r , c);
                }
            }
        }

        int count = 0;

        for (int i = 0 ; i < m ; i++){
            for (int j = 0; j < n ; j++){

                if (grid[i][j]== 0){
                    count++;
                }
            }
        }

        return count;
    }
};