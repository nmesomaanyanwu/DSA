class Solution {
public:
    string addStrings(string num1, string num2) {
        /*
        1. we look for the one which is bigger in size basically and then we fill the front of the other one with  0 
        2. We have a remainder for keepint the carry from the previous count 
        3. then for each one we add he remainder and m tehn add it to our output string
        */
        string a = num1;
        string b = num2;

        string path;
        int rem = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while(rem || j >=0 || i >= 0){
            int sum = rem;
            if (j >= 0) sum += b[j] - '0';
            
            if (i >= 0) sum += a[i] - '0';

            
            rem = sum / 10;

            sum = sum % 10;

            path.push_back('0' + sum);
            j--;
            i--;
        }

        reverse(path.begin() , path.end());
        return path;

        
    }
};