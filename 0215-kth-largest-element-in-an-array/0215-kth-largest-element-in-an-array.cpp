class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int>, greater<>> hp;
        int n = nums.size();

        for (int i = 0 ; i < n ; i++){
            if (hp.size() < k){
                hp.push(nums[i]);
            }
            else{
                if (nums[i] > hp.top()){
                    hp.pop();
                    hp.push(nums[i]);
                }
            }
        }

        return hp.top();
    }
};