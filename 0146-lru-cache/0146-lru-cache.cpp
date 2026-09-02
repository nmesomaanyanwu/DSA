class LRUCache {
public:
    // make the list variable and also he n -> repressnring the capacity
    list<int> nums{};
    int n;
    unordered_map<int , int> pairs;

    LRUCache(int capacity):n(capacity) {
        
    }
    
    int get(int key) {
        // check if this key exists with .count 
        auto it = find(nums.begin() , nums.end() , key);
        if (it != nums.end()){
            nums.splice(nums.begin() , nums , it);
            return pairs[key];
        }
        else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        
        // check if the value exist 
        auto it = find(nums.begin() , nums.end() , key);
        if (it != nums.end()){
            nums.splice(nums.begin(), nums, it);
            pairs[key] = value;
        }
        else{
            if (nums.size() < n){
                nums.push_front(key);
                pairs[key] = value;
            }
            else{
                int l = nums.back();
                pairs.erase(l); // get rid of the least recently used key pair 
                nums.pop_back(); // remove the least recently used 
                nums.push_front(key); // add the new one 
                pairs[key] = value;
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */