class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        /*
        our max width is 16 lets say that firstly 

        we know that passed on the ammount of words we have the spaces between then should be n-1

        so we wil hvae to drop a word if it passes our list 
        
        
        */
        vector<string> ans;
        int n = words.size();
        int pointer = 0;
        int start = 0;
        
       
       while (pointer < n){
        int start = pointer;  // to count tthe amount of words we want 
        int word_count = 0;
        string cur = "";
        

            while (pointer < n && word_count + words[pointer].size() + (pointer - start) <= maxWidth){
                word_count += words[pointer].size();
                pointer++;
            }

            // check how many words we have and what the pointer is at it hould point to the next one
            int num_of_words = pointer - start;
            int gaps = num_of_words - 1;

            //last line
            if (pointer == n || gaps == 0){

                for (int i = start ; i < pointer ; i++){
                    cur += words[i];

                    if (i != pointer -1){
                        cur += " ";
                    }
                }
                // pad remaining spaces on the right 
                cur += string(maxWidth - cur.size(), ' ');
            }
            else{
                // normal padding
                int spaces_to_fill = maxWidth - word_count;
                int remainder = spaces_to_fill % gaps;
                int e = spaces_to_fill / gaps;

                for (int i = start ; i < pointer; i++){
                    cur += words[i];

                if (i != pointer -1){
                    int spaces = e;

                    if (remainder > 0){
                        spaces++;
                        remainder--;
                    }
                    
                    cur += string(spaces , ' ');

                }
                
            }

         }
        ans.push_back(cur);

       }

       return ans;

    }
    
};