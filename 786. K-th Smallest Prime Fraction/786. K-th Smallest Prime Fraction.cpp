class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        // Custome comparator for the priority queue that will compare fractions
        auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[a.second] * arr[b.first];
        };

        // Define a priority queue with the custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare) > pq(compare);

        // Init the priority queue with fractions {0, j} (0 < j)
        for (int j = 1; j < arr.size(); ++j) {
            pq.push({ 0, j });
        }

        // Pop K - 1 elements from the priority queue to reach the K-th smallest fraction
        for (int j = 1; j < k; ++j) {
            pair<int, int> fraction = pq.top();
            pq.pop();

            // If we can construct a new fraction with a bigger numerator
            if (fraction.first + 1 < fraction.second) {
                pq.push({ fraction.first + 1, fraction.second });
            }
        }
        // The top of the priority queue is now our K-th smallest fraction
        // Ret the values from 'arr' correspponding to the indices of this fraction
        return { arr[pq.top().first], arr[pq.top().second] };
    }
};