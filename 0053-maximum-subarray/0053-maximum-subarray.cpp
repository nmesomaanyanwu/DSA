class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* im thnking if this is greedy how would i approach this question
        1)Firstly i will start and if a number makes it less than 0 start  the best we had so far then we literally leave it
        */
        if (nums.empty()) return 0;
        
        int max_best = nums[0];
        int best = nums[0];

        for (int i = 1 ; i < nums.size() ; i++){
            // we get the cur no if its better than our best we start best from this no else we just add the no 
            int cur = nums[i];
           
            // we have to see locally if its better o start at current or carry best with  current
            best = max(best + cur , cur);
            max_best = max(max_best , best);

        }

        return max(max_best , best);
        
    }
};