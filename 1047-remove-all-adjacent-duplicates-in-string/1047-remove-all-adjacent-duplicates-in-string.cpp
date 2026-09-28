class Solution {
public:
    string removeDuplicates(string s) {

        string ans = "";
        vector<char> st;
        unordered_set<char> unique;


        for (auto ch : s){

            if (st.empty()) {
                st.push_back(ch);
                continue;
            }
            
            if  (!st.empty() && st.back() == ch){
                st.pop_back();
                continue;
                
            }
            
            st.push_back(ch);
        }


        for (int i = 0 ; i < st.size() ; i++) ans+= st[i];

        return ans;

        
    }
};