class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*Lets do a dp approach to this question 
        were gonna do a bottom to top recurrence approach 
        1) basically we will start from the last index because the jumps required to reach the last index from the last is always 0
        2) Then we work our way backwards we check basically firstly if the no of jumps is greater than or equal to the difference in indexx and we just add 1 to the dp to show we need 1 jump from this array
        3) else if its less we check if  its greater than 1 and then also check if dp[cur+ 1] eists so we make that are dp approach until we get to the top
        4) if the top of the dp still ends up being -1 from when we intialized it then we return false else true  
        */

        vector<int> dp(nums.size() , -1);
      
        int n =nums.size();
        int end = n-1; // end index
        dp[end] = 0;

        for (int i = n - 2 ; i >= 0 ; --i){
            int cur = nums[i];
            // check if  cur is greater than or equal to diff between difference between indexes
            if (cur >= (end - i)){
                dp[i] = 1;
            }
            else{
                int id = i + 1;
                while (id <= end){
                    if (dp[id] != -1){
                        break;
                    }
                    ++id;   
                } 

                if (dp[id] != -1 && (cur >= (id - i))){
                    dp[i] = (id -i) + dp[i];
                } 

            }
            
        }


        if (dp[0] == -1) return false;
        else return true;
        
    }
};