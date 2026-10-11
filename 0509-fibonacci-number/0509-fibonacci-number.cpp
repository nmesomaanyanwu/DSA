class Solution {
public:
    int fib(int n) {
        /*
        Ok lets do a dp recurrence apprach 
        so basically we will start from the smallest numbers and make a v
        */
       if (n <= 1) return n;

       vector<int> dp(n+1);
       dp[0] = 0;
       dp[1] = 1; 

       for (int i = 2 ; i < n + 1 ; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
       }

       return dp[n];
    }
};