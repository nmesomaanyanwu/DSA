class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        /*Ok what im going to do is to build a prefix sum of the nums firstly 
        Then I'm going to build hashmap that will add the remaindesof numbers that divide by k and 
        if we have seen that remainder in our hashmap we add the count which means starting from all those positions after that remiander we could make a sum of k
        */
        int n = nums.size();
        unordered_map<int , int> rem;
        rem.insert({0 , 1});
        vector<int> prefix(n);
        int res = 0;

        for (int i = 0 ; i < n ; i++){
            if (i == 0){
                prefix[i] = nums[i];
            }
            else{
                prefix[i] = nums[i] + prefix[i - 1];
            }
        }

        for (int i = 0 ; i < n ; i++){
            int mod = ((prefix[i] % k) + k) % k;

            if (rem.count(mod)== 1){
                res += rem[mod];
            }

            rem[mod]++;
        }
        return res;
    }
};