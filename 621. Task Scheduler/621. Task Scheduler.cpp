class Solution {
public:
    int leastInterval(vector<char>& tasks, int cooling_period) {

        // Init vector to keep count of each task
        vector<int> task_count(26);
        // Variable to keep track of max count of a single task
        int max_single_task_count = 0;

        // Count the tasks and find out the task with the max count
        for (char task : tasks) {
            // convert character to an index between 0 -> 25
            task -= 'A';
            ++task_count[task];
            max_single_task_count = max(max_single_task_count, task_count[task]);
        }

        // Count how many tasks have the same count as maxCount
        int tasks_max_count = 0;
        for (int count : task_count) {
            if (count == max_single_task_count) {
                ++tasks_max_count;
            }
        }

        /**
        * Calculate the least interval
        * First part:: calculate min count required based on the most frequent task(max_single_task_count - 1)
        *    times (cooling_perid + 1)
        * Second part:: add the num of tasks that have the highest frequency (tasks_max_count)
        */
        int min_slots_required = (max_single_task_count - 1) * (cooling_period + 1) + tasks_max_count;

        // Return result is the max between the actual size of tasks and the min slots required
        return max(static_cast<int>(tasks.size()), min_slots_required);
    }
};