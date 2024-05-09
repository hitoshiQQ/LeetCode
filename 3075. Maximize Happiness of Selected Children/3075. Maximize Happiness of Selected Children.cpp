class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        // Sort the happiness vector in non-increasing order
        sort(happiness.rbegin(), happiness.rend());

        // Init a variable to store the accumulated max happiness sum
        long long maxHappinessSum = 0;

        // Iterate over the first K elements of the stored vector
        for (int j = 0, n = (int)happiness.size(); j < k; ++j) {
            // Calculate the modified happiness value by substracting the index 
            int modifiedHappiness = happiness[j] - j;

            // If the modified happiness value is pos, add it to the sum
            // Otherwise, add zero
            maxHappinessSum += std::max(modifiedHappiness, 0);
        }
        return maxHappinessSum;
    }
};