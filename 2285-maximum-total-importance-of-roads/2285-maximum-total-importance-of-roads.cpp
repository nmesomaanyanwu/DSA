class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        /*
         change in plans we want to maximize the total importance so we want the road that comes most freuwntly yo start and be the most imprtant 

         city - frequency 
         then we have frquency -importance 

        */

        vector<int> freq(n , 0);


        for (int i = 0 ; i < roads.size() ; i++){
            vector<int> cur = roads[i];
            freq[cur[0]]++;
            freq[cur[1]]++;
        }
        // after this we have the numbers and the amount of times they show up 

        vector<int> cities(n, 0); // we have city id

        for (int i = 0 ; i < n; i++){
            cities[i] = i;
        } 

        sort(cities.begin(), cities.end(), [&] (int a, int b){
            return freq[a] < freq[b];
        });
        // that sorted the citys in positions of importance  starteing from smallest to highest 

        vector<int> importance(n, 0);

        for (int i = 0 ; i < n ; i++){
            importance[cities[i]] = i+ 1;
        }

        // for maximum importance 
        long long  total = 0 ;

        for (int i = 0 ; i < roads.size() ; i++){
            vector<int> cur = roads[i];
            int a = cur[0];
            int b = cur[1];
            total = total + importance[a] + importance[b];

        }


        return total;
        
    }
};