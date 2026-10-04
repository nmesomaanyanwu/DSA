class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Ok so what we are gonna do is firstly we will 
        1) go through each string and sort it then check if the sorted string exists in hashmap 
        2) if yes just append it 
        3) if no make the sorted string a key and append the original o one 
        */
        unordered_map<string , vector<string>> anagrams;
        int n = strs.size();

        for (int i = 0 ; i < n ; i++){
            string current = strs[i];
            string sorted = current;
            sort(sorted.begin() , sorted.end());
        
            anagrams[sorted].push_back(current);
           
        }
        vector<vector<string>> result;

        for (auto& [key , value] : anagrams){
            result.push_back(value);
        }

        return result;

    }
};