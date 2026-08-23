class KthLargest {
    priority_queue<int , vector<int> , greater<>> hp; // min-heap
    int max_length;

public:

    KthLargest(int k, vector<int>& nums):max_length(k) {
        for (int i = 0 ; i < nums.size();i++){
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
    }
    
    int add(int val) {
        if (hp.size() >= max_length){
            if (val > hp.top()){
                hp.pop();
                hp.push(val);
            }
        }
        else{
            hp.push(val);
        }
        
        return hp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */