class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        /*
        ok so basically get the minimum and maximum values 
        start at mid
        we then will check if 10 is possibe if its nit possible move right 
        if it is possibel keep it as the best so far then move left and check 
        */

        int best = INT_MAX;
        int n = bloomDay.size();

        if (n < (1LL * m * k)) return -1;

        int low  = *min_element(bloomDay.begin(), bloomDay.end());;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        // get the low and high number 
        while (low <= high){
            int mid = (low + high)/2 ;
            int cur  = mid;
            int count = 0;
            int bouquets = 0;

            for (int  i = 0 ; i < bloomDay.size(); i++){
                
                if (bloomDay[i] <= cur){
                    count++;
                }
                else{
                    //check how many boquets the count can make 
                    bouquets += (count / k);
                    count = 0;
                }
            }
            bouquets += count / k;

            if( bouquets >= m){
                best = min(best , cur);
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }


        return best;
    }
};