class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        /*
         we make a function which will 
         take in the  begining of an array and end of array low and high
         while  low < high we basically
         keep recurively splitting the function   
         and then we merge it up from when low >= high

        */
        auto merge = [&](auto&& self , int low , int mid , int high)-> void{
            // so i think we need to sort like 
            vector<int> temp;

            int i = low;
            int j = mid + 1;

            while ((i <= mid) && (j <= high)){

                if (nums[i] < nums[j]){
                    temp.push_back(nums[i]);
                    i++;
                }
                else{
                    temp.push_back(nums[j]);
                    j++;
                }
            }

            while (i <= mid){
                temp.push_back(nums[i]);
                i++;
            }

            while (j <= high){
                temp.push_back(nums[j]);
                j++;
            }

            for (int k = 0 ; k < temp.size(); k++){
                nums[low + k] = temp[k];
            }

        };


        auto mergesort = [&](auto&& self, int low , int high) -> void{
            if (low < high){
                int mid = (high + low) / 2;
                self(self , low , mid);
                self(self , mid + 1 , high);
                merge(merge, low , mid , high);
            }
            
        };

        mergesort(mergesort , 0 , nums.size() - 1);

        return nums;


        
    }
};