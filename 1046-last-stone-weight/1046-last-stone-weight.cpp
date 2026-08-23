class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> hp; // this is a max_heap;

        for (int i = 0 ; i < n ; i++){
            hp.push(stones[i]);
        }

        while (hp.size() > 1){
            int a = hp.top();
            hp.pop();
            int b = hp.top();
            hp.pop();

            if (a == b){
                continue;
            }
            if (a != b){
                int n = a - b;
                hp.push(n);
            }
        }

        if (!hp.empty()){
            return hp.top();
        }else{
            return 0;
        }
    }
};