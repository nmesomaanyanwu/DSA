class Solution {
public:
    string smallestSubsequence(string s) {
        /*
        1) okay so we have a vector that we will treat as a stack then wil take in chars 
        2) we have a hashmap that shows the last ocuurence of each  unique letter 
        3) we keep a set to make sure we dont get any duplicates 
        4) if we have no duplicates so far and st is not empty and the top of the stack is greater than the current element and the last index of the st is greater than i then we should pop and remove fromn the set unique
        */

        unordered_map<char , int> last_occurrence; // this will keep track of the last occurrence of each unique element 
        unordered_set<char> unique;
        vector<int> st; // so it would be easier to  join the chars into a string 

        for (int i = 0 ; i < s.size() ; i++) last_occurrence[s[i]] = i;


        for (int i = 0 ; i < s.size() ; i++){

            // get the current char 
            int cur = s[i];

            if (unique.count(cur) == 0 ){
                // we check if theres a stack and if the top of the stack is greater and it shows up later
                while (!st.empty() && (st.back() > cur) && (last_occurrence[st.back()] > i)){
                    unique.erase(st.back());
                    st.pop_back();
                }
                
                st.push_back(cur);
                unique.insert(cur);
                
            }
            
        };

        string ans;

        for (int j  = 0 ; j < st.size() ; j++) ans += st[j];
        
        return ans;
    }
};