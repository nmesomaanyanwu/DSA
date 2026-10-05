class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        if ( n == 1)return true;

        int count = 1;
        int l = 0;

        for (int i = 1 ; i < (2*n) ; i++){

            if (nums[i % n] >= nums[(i-1) % n]){
                count++;
            }
            else if (nums[i % n] < nums[(i -1) % n]){
                count = 1;
            }

            if (count == n){
                return true ;
            }
            
        }


        return  count == n;
       
        


    }
};