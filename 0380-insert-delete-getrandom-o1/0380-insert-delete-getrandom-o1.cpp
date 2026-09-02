class RandomizedSet {
    vector<int> nums; 
    unordered_map<int , int> mp;// used to store the vectors index for the val 
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.count(val)){
            return false;
        }

        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {

        if (mp.count(val)== 0){
            return false;
        }

        int index = mp[val];

        int b = nums.back();

        nums[index] = b ; // move the last element to the place we want to get rid off

        mp[b] = index; // update the last elements index

        nums.pop_back();

        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        // we get a random int 

        int randomIndex = rand() % nums.size();

        return nums[randomIndex];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */