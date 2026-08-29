class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long n = cost.size();
        map<int , int> hp;
        long long total_cost = 0;
       
        for (int i = 0 ; i < n ; i++){
            hp[nums[i]] += cost[i];
            total_cost += cost[i];
        }

        long long current = 0;
        long long num;
        for (auto [k, v] : hp){
            current += v;

            if (current * 2 >= total_cost){
                num = k;
                break;
            }
        }

        // num is the number we are trying to get our list doen to balance out 
        long long m_cost = 0;

        for (int i = 0 ; i < n ; i++){
            long long diff = abs(nums[i] - num);
            m_cost += (diff * cost[i]);
        }

        return m_cost;
 
    }
};