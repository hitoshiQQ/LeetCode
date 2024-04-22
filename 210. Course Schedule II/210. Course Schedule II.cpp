class Solution {
public:
    // Func to find the order of courses you should take to finish all courses
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list representattion of graph
        vector<vector<int>> graph(numCourses);

        // Vector to store the number of incoming edges for each node
        vector<int> inDegree(numCourses, 0);

        // Build graph and fill inDegree data
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisitesCourse = pre[1];

            // Edge from prereq to course
            graph[prerequisitesCourse].push_back(course);
            ++inDegree[course];
        }

        // Queue for bfs
        std::queue<int> queue;

        // Enqueue all courses that don't require prerequisites
        for (int j = 0; j < numCourses; ++j) {
            if (inDegree[j] == 0) {
                queue.push(j);
            }
        }

        // Vector to store the order of courses to take
        vector<int> order;

        // Process nodes with no incoming edges
        while (!queue.empty()) {
            int currentCourse = queue.front();
            queue.pop();
            order.push_back(currentCourse);

            // For each course that comes after the current course
            for (int nextCourse : graph[currentCourse]) {
                // Decrase the in-degree and if it becomes zero, add it to the queue
                if (--inDegree[nextCourse] == 0) {
                    queue.push(nextCourse);
                }
            }
        }
        // If we were able to include all courses in the order list , return it
        // Otherwise, the prerequisites form a cycle and we cannopt complete all course
        if (order.size() == numCourses) {
            return order;
        }
        else {
            // empty vector 
            return vector<int>();
        }
    }
};