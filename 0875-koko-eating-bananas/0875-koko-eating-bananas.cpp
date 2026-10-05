class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
        */

        int low = 1;
        int high = *max_element(piles.begin() , piles.end());
        int best = high;

        while(low <= high){
            int m = (low + high)/ 2;

            long long count = 0;
            for (int i = 0 ; i < piles.size() ; i++){
                int cur = piles[i];

                int rem = cur % m;
                int n = cur/m;
                count += n;
                if (rem != 0){
                    count++;
                }
            }

            // we check if this is greater than h
            if (count  > h){
                low = m + 1;
            }
            else{
                best = min(best , m);
                high = m -1;
            }
        }

        return best;

    }
};