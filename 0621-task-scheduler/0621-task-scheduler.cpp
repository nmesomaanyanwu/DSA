class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       /* We want to minimize the amount of weights we have inbetween so we start from the task that have the most frquency 
       */
        unordered_map<char , int> freq;
        priority_queue<int> mh;
        queue<pair<int, int>> times;

        for (int i = 0 ; i < tasks.size(); i++){
            freq[tasks[i]]++;
        }

        for (auto [k ,v]: freq){
            mh.push(v);
        }

        int time = 0;
        // we make a heap which will contain these frequencies and each time we process a frequency we add the weight time plus the remainibg frequency to our queue ready to be processed again 
        while(!mh.empty() || !times.empty()){
            time++;
            if (!mh.empty()){
                int cnt = mh.top() - 1;
                mh.pop(); // removes it from the heap
                if (cnt){
                    times.push({cnt ,time + n});
                }
            }

            // we check for if the time is the current time to push back our waiting tasks to the heap
            if (!times.empty()){
                auto [freq , t] = times.front();

                if (time == t){
                    times.pop();
                    mh.push(freq);
                }
            }

        }

        // We then check if any have reach 0 if it has we dont add to our queue anymore and until both maxheap and queue are empty we continue processing 


        // we return the total time we manage to accumulate
        
        return time;
    }
};