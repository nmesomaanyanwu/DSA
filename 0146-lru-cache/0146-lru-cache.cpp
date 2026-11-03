class LRUCache {
    list<pair<int,int>> buff;
    unordered_map<int , list<pair<int , int>>::iterator> hm;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (hm.count(key) == 1){
            auto it = hm[key];
            int value = it->second;
            buff.erase(it);
            buff.push_back({key , value});

            hm[key] = prev(buff.end());

            return value;

        }

      return -1;
    }
    
    void put(int key, int value) {

        if (hm.count(key) == 1){
            auto it = hm[key];
            buff.erase(it);

            buff.push_back({key , value});


            hm[key] = prev(buff.end());

        }
        else{
            if (buff.size() == cap){
                auto cur = buff.front().first;

                buff.erase(buff.begin());

                hm.erase(cur);
            }

            buff.push_back({key , value});
            auto it = prev(buff.end());

            hm[key] = it;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */