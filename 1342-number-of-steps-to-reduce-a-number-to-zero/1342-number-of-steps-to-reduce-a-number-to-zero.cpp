class Solution {
public:
    int numberOfSteps(int num) {
        int remaining = num;
        int count = 0;

        while (remaining != 0){

            if (remaining % 2 == 0){
                remaining /= 2;
                count++;
            }
            else{
                remaining -= 1;
                count++;
            }
        }

        return count;
    }
};