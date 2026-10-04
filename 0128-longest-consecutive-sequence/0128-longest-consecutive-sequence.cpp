class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_count = 0;

        unordered_set<int> s;

        for (auto num : nums){
            s.insert(num);
        }

        for (int n : s){
            
            if (s.count(n - 1) == 0){

                int count = 0;
                int j = n;

                while(s.count(j) == 1){
                    count++;
                    j++;
                }
                max_count = max(count , max_count);
            }
        }

        return max_count;
        
    }
};