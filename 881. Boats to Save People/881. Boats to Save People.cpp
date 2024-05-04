class Solution {
public:
    /**
    * @brief Method to find out the number of boats necessary to rescue all people
    * @param people - List of weights of the people
    * @param limit - Weight limit of the boat
    */
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;

        ranges::sort(people);

        for (int j = 0, i = people.size() - 1; j <= i; ++res) {
            const int remain = limit - people[i--];
            if (people[j] <= remain)
                ++j;
        }
        return res;
    }
};