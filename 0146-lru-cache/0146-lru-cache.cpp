class LRUCache {
public:
    // make the list variable and also he n -> repressnring the capacity
    list<pair<int,int>> nums{}; // nums stores key value pairs
    int n;
    unordered_map<int , list<pair<int, int>>::iterator> pairs; // pairs will store key and memory addresses for the key value 

    LRUCache(int capacity):n(capacity) {
        
    }
    
    int get(int key) {
        // check if this key exists with .count 

        if (pairs.count(key) == 0){
            return -1 ;
        }
        
        auto node = pairs[key]; // this represents the key and value 

        nums.splice(nums.begin() , nums , node);

        int value = node->second;

        return value; // this will be the value 
        
    }
    
    void put(int key, int value) {
        
        // check if the value exist 
        
        if (pairs.count(key)){
            auto node = pairs[key];
            node->second = value;
            nums.splice(nums.begin(), nums, node);
        }
        else{
            if (nums.size() < n){
                nums.push_front({key , value});
                pairs[key] = nums.begin();
            }
            else{
                auto l = nums.back();
                pairs.erase(l.first); // get rid of the least recently used key pair 
                nums.pop_back(); // remove the least recently used 
                nums.push_front({key, value}); // add the new one 
                pairs[key] = nums.begin();
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