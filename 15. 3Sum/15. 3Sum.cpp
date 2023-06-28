/*
1. Sorting;
2. Try over the first number;
3. Find several corresponding numbers;

If you search from higher to lower numbers, the first number will be in ascending order;
The second and third are greater than the first;
The third is greater than the second;
*/

// acceleration for better runtime
const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        //res.reserve(nums.size() * nums.size());
        // if include, loss memory

        for(int j = 0; j + 2 < (int)nums.size();++j){
            // optimize - Excluding the same numbers
            if(j > 0 && nums[j] == nums[j-1]){
                continue;
            }

            // optimize - Excluding three small numbers
            if(nums[j] + nums[j+1] + nums[j+2] > 0 ){
                continue;
            }
            
            // optimize - Excluding three large numbers
            if(nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0 ){
                continue;
            }

            int i = j + 1;
            int k = (int)nums.size() - 1;
            for(int i = j + 1;i < k;++i){

                while(i < k - 1 && nums[j] + nums[i] + nums[k] > 0){
                    --k;
                }
                assert(j < i && i < k );
                if(nums[j] + nums[i] + nums[k] == 0){
                    if(res.empty() || nums[j] != res.back()[0] || nums[i] != res.back()[1] || nums[k] != res.back()[2]){
                        res.push_back({nums[j],nums[i],nums[k]});
                    }
                    
                }
            }
        }
        return res;
    }
};
