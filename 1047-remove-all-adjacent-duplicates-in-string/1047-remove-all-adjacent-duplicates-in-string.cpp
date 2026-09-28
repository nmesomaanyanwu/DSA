class Solution {
public:
    string removeDuplicates(string s) {

        string ans = "";
        vector<char> st;
        unordered_set<char> unique;


        for (auto ch : s){

            if (st.empty() || !st.empty() && st.back() != ch) st.push_back(ch);
            else{
                while (!st.empty() && st.back() == ch){
                st.pop_back();
                }
            }
            
        }


        for (int i = 0 ; i < st.size() ; i++) ans+= st[i];

        return ans;

        
    }
};