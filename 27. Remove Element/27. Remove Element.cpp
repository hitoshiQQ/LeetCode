class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }

        // create 2 pointers
        int j = 0,i = 0;

        while(i < nums.size()){

            // skip the number to be removed
            if(nums[i] == val){
                ++i;
            }else{

                //copy the values into the previous cell 
                nums[j] = nums[i];
                ++j;++i;
            }
        }
        return j;
    }
};