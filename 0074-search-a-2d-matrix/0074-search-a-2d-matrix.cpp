class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        so each row has increasing orderr
        */
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int lr = 0;
    
        int rr = rows -1;
      

        // so first we are gonna binary search on the rows and then columsn

        while (lr  <= rr){
            // ok now we check the end of each row 
            int m = (lr + rr) / 2;

            if (matrix[m][cols - 1] >= target && matrix[m][0] <= target){

                // we  binary search into the cols 
                int l = 0;
                int r = cols -1;

                while (l <= r){
                    int mc = (l + r) / 2;

                    if (matrix[m][mc] == target) return true;
                    else if (matrix[m][mc] < target){
                        l = mc + 1;
                    }
                    else if (matrix[m][mc] > target){
                        r = mc - 1;
                    }
                
                }
                return false;
            }
            else if (matrix[m][cols -1] < target){
                // so the last element if this particular row is less than target
                lr = m + 1;
            }
            else if (matrix[m][0] > target){
                rr = m - 1;
            }

        }

        return false;
    }
};