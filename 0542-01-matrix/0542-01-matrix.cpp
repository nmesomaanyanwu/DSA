class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*Ok the way im gonna solve this question is that ill put every  0 on the  quwue that sistance from 0 to itself is one in  so we do nothing then we will put like  1 on the stack and then from the ones 2 but im thinking do i actually need do i need a sepaarte answer grid or can i use the same grid*/
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int , int>> moves = {{1, 0}, {-1 , 0}, {0 , 1}, {0, -1}};
        vector<vector<int>> visited (rows , vector<int>(cols, 0));
        queue<vector<int>> q;

        // firstly put all the zeros 

        for (int r = 0 ; r < rows ; ++r){
            for (int c = 0 ; c < cols ; ++c){
                if (mat[r][c] == 0){ 
                    q.push({r , c });
                    visited[r][c] = 1;
                }
            }
        }

        int t = 0;

        while (!q.empty()){
            int layer = q.size();

            for (int i = 0 ; i < layer ; i++){
                vector<int> cur = q.front();
                q.pop();
                int row = cur[0];
                int col = cur [1];
                
                mat[row][col] = t;
            

                for (auto [v , h] : moves){
                    int nr = row + v;
                    int nc = col + h;

                    if (nc < 0 || nc >= cols || nr >= rows || nr < 0) continue;

                    if (visited[nr][nc])continue;

                    visited[nr][nc] = 1;
                    q.push({nr , nc });
                }

            }
            ++t;

        }



        return mat;

    }
};