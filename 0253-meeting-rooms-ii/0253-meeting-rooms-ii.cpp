class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
    /*Keep a queue of all the start intervals in one queue and another of all the stop in another we start with the minimum 
    if the min time between the start queue and end queue is start queue we add a count to show that we need another meeting room 
    if its the end queue it shows that one has finished or some so it now shows haow many meeting romms are currently 
    i think we want to return teh max amount of meeting rooms weve had to use at once 
    if both start and end have same number the start takes priority
    */
    int max_count = 0;

    int count = 0;
    priority_queue<int , vector<int>, greater<> > start;
    priority_queue<int , vector<int>, greater<> > stop;


    for (int i = 0 ; i < intervals.size(); i++){
        vector<int> cur = intervals[i];

        int st = cur[0];
        int sp = cur[1];

        start.push(st);
        stop.push(sp);
    }

    while (!start.empty()){
        int cur_start = start.top();
        int cur_stop = stop.top();

        if (cur_start < cur_stop){
            count++;
            start.pop();

        }
        else{
            count--;
            stop.pop();

        }

        max_count = max(max_count , count);
    }

    return max_count;

      
    }
};