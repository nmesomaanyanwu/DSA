class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    /* Were gonna use the stack data structure  and how this will work 
    we wil put a pair of int into our stack firts the num seond the index 
    */
    int n = temperatures.size();
    stack<pair<int , int>> st;
    vector<int> ans(n , 0);


    for (int i = 0 ; i < n ; ++i){
        int cur = temperatures[i];

        while (!st.empty() && st.top().first < cur){
            ans[st.top().second] = i - st.top().second; // this wll be the immediate better temp 
            st.pop();
        }

        st.push({cur , i});
    }

    return ans;

        
    }
};