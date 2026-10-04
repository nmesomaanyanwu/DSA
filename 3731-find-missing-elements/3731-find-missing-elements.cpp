class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        
        priority_queue<int, vector<int>, greater<>> hp(nums.begin(), nums.end());

        int start = hp.top() + 1;
        hp.pop(); 
    
        while (!hp.empty()){
            if (start != hp.top()){
                ans.push_back(start);
            }
            else{
                hp.pop();
            }
            start++;
        }

         return ans;
    }
};