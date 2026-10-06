class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*How im going to solve this question 
        1) ill do a mult-source BFS search for this one and  so would push all the 2's to the queue 
        2) then i will count each level until all oranges turn rotten and then return 0;
        */
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        int minutes = 0;
        
        vector<pair<int , int>> moves = {{1 , 0}, {-1, 0}, {0,1}, {0 , -1}};

        queue<pair<int, int>> q; // to store the rotten oranges 

        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){
                
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        // now we check 
        while(!q.empty()){

            int level = q.size();

            for (int i = 0 ; i < level ; i++){

                auto [r , c] = q.front();
                q.pop();

                for (auto [v , h] : moves){
                    int nr = r + v;
                    int nc = c + h;

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                    if (grid[nr][nc] != 1) continue;

                    grid[nr][nc] = 2;

                    q.push({nr , nc}); 

                }

            }

            minutes++;

        }

        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){

                if (grid[i][j] ==1) return -1;
            }
        }

        return max(0, minutes - 1);;

        
    }
};