class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        class DSU{
            public:
            vector<int> parent;
            vector<int> size;
            int components = 0;

            DSU(int n):size(n, 0), parent(n){

                for (int i = 0; i < n ; i++){
                    parent[i]= i;
                }
            }

            int find(int x){
                
                if (parent[x] != x){
                    parent[x] = find(parent[x]);
                }

                return parent[x];
            }

            bool unite(int a , int b){
                int ra = find(a);
                int rb = find(b);

                if (ra == rb) return false;

                if (size[ra] < size[rb]){
                    swap(ra , rb);
                }

                parent[rb] = ra;
                size[ra]+= size[rb];

                components--;
                return true;
            }

        };

        // intialize the class and then get the amount of components and then match 
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int, int>> moves = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};

        DSU dsu(rows*cols);

        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){

                if (grid[i][j] == '1'){
                    dsu.components++;
                }
            }
        }

        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){

                if (grid[i][j] == '1'){

                    for (auto [r , v]: moves){
                        int nr = r+ i;
                        int nc = v + j;

                        if (nr <0 || nr >=rows || nc <0 || nc >= cols)continue;

                       
                        if (grid[nr][nc] == '0') continue;

                        dsu.unite(i * cols + j , nr * cols + nc);
                    }
                }
            }
        }

        return dsu.components;

    }
};