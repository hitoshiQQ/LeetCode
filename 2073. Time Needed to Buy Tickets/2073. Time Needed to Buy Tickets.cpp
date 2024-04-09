class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        // init the total time to 0
        int totalTime = 0;

        // Get the number of people in the line
        int n = tickets.size();

        for (int j = 0; j < n; ++j) {

            // If the person is before or at pos K, only buy until the number of tickets
            // the kth person needs
            if (j <= k) {
                totalTime += min(tickets[k], tickets[j]);

            }
            else {
                // If the person is after the kth person, they can only buy until one less than the number
                // of tickets the kth person needs, because when the kth get their last tickets
                // these ones can't buy any more
                totalTime += min(tickets[k] - 1, tickets[j]);
            }
        }
        return totalTime;
    }
};