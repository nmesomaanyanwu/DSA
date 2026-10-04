class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) return false;

        vector<int> schars(26 , 0);
        vector<int> tchars(26 , 0);

        for (int i = 0 ; i < s.size() ; i++){

            schars[s[i] -  'a']++;
            tchars[t[i] - 'a']++;
        }
        
        for (int j = 0 ; j < 26 ; j++){
            if (schars[j] != tchars[j]) return false;
        }

        return true;
    }
};