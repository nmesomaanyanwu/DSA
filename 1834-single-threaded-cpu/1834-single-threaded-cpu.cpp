class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;

        auto cmp = [](const vector<int>& a , const vector<int>& b){

            if (a[1] != b[1]){
                return a[1] > b[1];// get the smaller of the end times 
            }
            else{
                return a[2] > b[2]; // get the smaller of the indexes 
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> hp(cmp);

        vector<vector<int>> sorted; 

        for (int i = 0 ; i < tasks.size(); i++){
            int start = tasks[i][0];
            int end = tasks[i][1];

            sorted.push_back({start ,  end , i});
        }
        sort(sorted.begin() , sorted.end()); // this will give us the optimal way to begin 

        long time = 0 ;

        int i = 0 ;


        while (i < sorted.size() || !hp.empty()){

            // if our heap is empty and our time is less than  our current sorted we want to make time teh sorted start 
            if (hp.empty() && time < sorted[i][0]){
                time = sorted[i][0];
            }

            // we have to look for all teh avaliable times during this period 
            while (i < sorted.size() && sorted[i][0] <= time){
                hp.push(sorted[i]);
                i++;
            }

            // from these avaliable times we have to pop the one tahts the cpu will do and add to our ans vector 
            vector<int> cur = hp.top();
            hp.pop();
            ans.push_back(cur[2]);

            // update time for the next task
            time += cur[1];
        }

        return ans;
        
    }
};