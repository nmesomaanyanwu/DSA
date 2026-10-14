class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        /*I can do this with bucket sort literally*/
        int n = words.size();
        unordered_map<string , int> freq;
        vector<vector<string>> bucket(n + 1);
        vector<string> ans;
        for (auto& word: words) freq[word]++;

        for (auto& [no , count]: freq){
            bucket[count].push_back(no);
        }


        for (int i = n ; i >= 1 ; i--){
            vector<string>& cur = bucket[i];
            if (cur.empty()) continue;
            sort(cur.begin(), cur.end());
            for (int j = 0 ; j < cur.size(); j++){
                ans.push_back(cur[j]);
                k--;
                if (k == 0) return ans;
            }
        }

        return ans;

        //
    }
};