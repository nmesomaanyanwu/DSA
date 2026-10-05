class TimeMap {
public:
    unordered_map<string , vector<pair<int , string>>> time; // time hashmap 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& cur = time[key];

        int l = 0;
        int r = cur.size() -1;
        int index = -1;

        while (l <= r){
            int m = (l +r)/2;

            if (cur[m].first == timestamp){
                return cur[m].second;
            }
            else if (cur[m].first < timestamp){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }

        if (r == -1) return "";
        return cur[r].second;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */