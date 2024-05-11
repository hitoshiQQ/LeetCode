class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        int numWorkers = quality.size();
        vector<pair<double, int>> workerRat(numWorkers);

        // Generate wage to quality ratios for all workers and store them with the quality
        for (int j = 0; j < numWorkers; ++j) {
            workerRat[j] = { (double)wage[j] / quality[j], quality[j] };
        }

        // Sort the workers based on their wage/quality ratio, lower ratio means more cost-effective
        sort(workerRat.begin(), workerRat.end());

        // Max heap to maintain the top K largest qualities
        priority_queue<int> qualityMaxHeap;

        // Init min cost with an high value
        double minCost = 1e9;

        // Total quality of the hired workers
        int totalQuality = 0;

        // Loop through the sorted worker ratios
        for (auto& [ratio, workerQuality] : workerRat) {
            // Add current workers quality to the total quality
            totalQuality += workerQuality;
            // Add current workers quality to max heap
            qualityMaxHeap.push(workerQuality);

            // Once we have a group of K workers
            if (qualityMaxHeap.size() == k) {
                // Calc the cost of hiring the current group and update min cost if necessary
                minCost = min(minCost, totalQuality * ratio);

                // Remove the worker with the highest quality as we want to try for a more cost-effective group next
                totalQuality -= qualityMaxHeap.top();
                qualityMaxHeap.pop();
            }
        }
        return minCost;
    }
};