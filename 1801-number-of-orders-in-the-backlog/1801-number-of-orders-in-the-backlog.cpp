class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        /*the idea 
        we want separate backlogs for buy and sell
        the buy one will return the max price 
        the sell will return the lowest price first 
        */
        int n = orders.size();

        auto highest_price = [](const vector<int>& a , const vector<int>& b ){
            return a[0] < b[0];

        };

        auto lowest_price = [](const vector<int>& a , const vector<int>& b ){
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(highest_price)> buy(highest_price);

        priority_queue<vector<int>, vector<vector<int>>, decltype(lowest_price)> sell(lowest_price);


         for (int i = 0 ; i < n ; i++){
            vector<int> cur = orders[i];
            int price = cur[0];
            int amount = cur[1];
            int type = cur[2];

            if (type == 0){
                if (!sell.empty()){
                    while(!sell.empty() && price >= sell.top()[0]){
                        //we get our amount if its greater 
                        if (amount >= sell.top()[1]){
                            amount-= sell.top()[1];

                            sell.pop();

                            if (amount == 0){
                                break;
                            }
                            
                        }
                        else{// if sellers amount is greater
                            vector<int> cur = sell.top();
                            sell.pop();
                            int temp = cur[1];
                            temp -= amount;
                            cur[1] = temp;
                            sell.push(cur);
                            amount = 0;
                            break;
                        }
                    }
                    if (amount != 0){
                        buy.push({price , amount , type});
                    }

                }
                else{
                    buy.push(cur);
                }
            }
            else{ // type is 1 which is a sell order 
                if (!buy.empty()){
                    while (!buy.empty() && buy.top()[0] >= price){

                        if (amount >= buy.top()[1]){
                            amount-= buy.top()[1];

                            buy.pop();

                            if (amount == 0){
                                break;
                            }

                        }
                        else{
                            vector<int> cur = buy.top();
                            buy.pop();
                            int temp = cur[1];
                            temp -= amount;
                            cur[1] = temp;
                            buy.push(cur);
                            amount = 0;
                            break;

                        }
                    }

                    if (amount != 0){
                        sell.push({price , amount , type});
                    }

                }
                else{
                    sell.push(cur);
                }

            }
         }

        // ok when we are done placing all of them then we look for whats remaining in each
        long long total = 0;

        while (!buy.empty()){
            vector<int> cur = buy.top();
            int amount = cur[1];
            total += amount;
            buy.pop();
        }

        while (!sell.empty()){
            vector<int> cur = sell.top();
            int amount = cur[1];
            total += amount;
            sell.pop();
        }


        return total % 1000000007;
    }
};