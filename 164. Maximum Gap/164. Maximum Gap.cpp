struct Bucket {
    int min;
    int max;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        if (nums.size() < 2) {
            return 0;
        }

        const int mini = ranges::min(nums);
        const int maxi = ranges::max(nums);
        if (mini == maxi) {
            return 0;
        }

        const int gap = ceil((maxi - mini) / (double)(nums.size() - 1));
        const int bucketSize = (maxi - mini) / gap + 1;
        vector<Bucket> buckets(bucketSize, { INT_MAX, INT_MIN });

        for (const int num : nums) {
            const int j = (num - mini) / gap;
            buckets[j].min = min(buckets[j].min, num);
            buckets[j].max = max(buckets[j].max, num);
        }

        int res = 0;
        int previousMax = mini;

        for (const Bucket& bucket : buckets) {
            if (bucket.min == INT_MAX) {
                continue;
            }

            res = max(res, bucket.min - previousMax);
            previousMax = bucket.max;
        }
        return res;
    }
};