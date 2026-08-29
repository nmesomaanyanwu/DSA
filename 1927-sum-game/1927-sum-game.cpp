class Solution {
public:
    bool sumGame(string num) {
        /*Ok so like we have an invariant each game which is the num of '?'
        we want to count the sum on the right side some on the left side , num of question mark s on the right and num on the left.
        Based on teh difference in their sums which we are tryong to fulfill 
        by checking the num of questiosn * 9/2 will equla because ideally we want eevrything to match
        
        */
        int n = num.size();

        int left_sum = 0;
        int right_sum = 0;
        int right_questions = 0;
        int left_questions = 0;

        for (int i = 0 ; i < n ; i++){
            if (i < (n /2)){
                if (num[i] == '?'){
                    left_questions += 1;
                }else{
                    left_sum += num[i] - '0';
                }

            }
            else{
                if (num[i] == '?'){
                    right_questions += 1;
                }else{
                    right_sum += num[i] - '0';
                }

            }

        }


        int total = right_questions + left_questions;

        if (total % 2 == 1){
            return true;
        }
        else{
            int diff =  left_sum - right_sum;

            int moves = right_questions - left_questions;

            if (moves * (9) == diff * 2){
                return false;
            }

            return true;
        }
        
    }
};