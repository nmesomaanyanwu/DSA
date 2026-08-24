class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> letters(256 , 0);

        int l = 0;
        int count = 0;
        int max_count = 0;

        for (int r = 0 ; r < s.size(); r++){
            count++;
            letters[s[r]]++;

            while (letters[s[r]] > 1){
                count--;
                letters[s[l]]--;
                l++;
            }
            max_count = max(max_count , count);
            
        }
        return max_count;
    }
};