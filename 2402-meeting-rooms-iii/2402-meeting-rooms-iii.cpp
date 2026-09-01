class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    
        // make a map for rooms to count starting from 0 
        map<int, int> rooms;

        auto cmp = [](const vector<long>&  a , const vector<long> b){
            long e_1 = a[1];
            long e_2 = b[1];
            long r_1 = a[2];
            long r_2 = b[2];

            if (e_1 != e_2){
                return e_1 > e_2; // min heap on the end time 
            }
            else{
                return r_1 > r_2; // min heap on the r_time 
            }
        };

        priority_queue<vector<long>, vector<vector<long>>, decltype(cmp)> hp(cmp);

        // make a priority queue thats holds 3 spaces [start time , end time , room]
        // its gonna depend on which end time is lower first then which room is lower if their are a draw
        priority_queue<int, vector<int> , greater<>> avaliable; // rooms that are avaliable 

        for (int i = 0 ; i < n ; i++){
            avaliable.push(i); // at the beginning all rooms are avaliable 
        }

        sort(meetings.begin() , meetings.end());

        //we have a for loop   to make our ap of romms and meetings 
        for (int i = 0 ; i < meetings.size() ; i++){
            long start = meetings[i][0];
            long end = meetings[i][1];

            // if this current start time is greater than the end of the top end time we remove the top element  and at its room as avaliable 
            while (!hp.empty() && hp.top()[1] <= start){
                vector<long> t = hp.top();
                hp.pop();
                avaliable.push(t[2]); // push the room as avaliable 
            } 

            if (!avaliable.empty()){
                int r = avaliable.top();
                avaliable.pop();
                hp.push({start , end , r}); 
                rooms[r]++;
            }
            else{
                vector<long> s = hp.top();
                hp.pop();
                vector<int> current = meetings[i];
                long diff = current[1] - current[0]; // this is the time period of the current delayed one
                hp.push({s[1], s[1] + diff , s[2]});
                rooms[s[2]]++;
            }

        }

        // we add rooms from 0- n-1 and if our queue is n.size for the next we give it its new time and room of our first 
        int max_count = 0;

        for (auto [r , f]: rooms){
            if (f > max_count){
                max_count = f;
            }
        }

        for (auto [r , f]: rooms){
            if (f == max_count){
                return r;
            }
        }

        return 0;




        
    }
};