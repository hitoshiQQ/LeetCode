class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Graph where each node is a course
        vector<vector<int>> graph(numCourses);

        // Indegree array to keep track pf prerequisites
        vector<int> inDegree(numCourses);

        // Process prerequisites to build the graph and update indegrees
        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prereq = prerequisite[1];

            // Add an edge from prereq to course
            graph[prereq].push_back(course);

            // Increment indegree of the course
            ++inDegree[course];
        }
        // Queue to store courses with no prerequisites
        queue<int> noPrereqCourses;
        for (int j = 0; j < numCourses; ++j) {
            if (inDegree[j] == 0) {
                noPrereqCourses.push(j);
            }
        }

        // Counteer for finished courses
        int finishedCount = 0;
        while (!noPrereqCourses.empty()) {
            int current = noPrereqCourses.front();
            noPrereqCourses.pop();
            ++finishedCount;

            // Reduce indegree for all neighbors, if it drops to 0, enqueue
            for (int neighbor : graph[current]) {
                if (--inDegree[neighbor] == 0) {
                    noPrereqCourses.push(neighbor);
                }
            }
        }
        // If we have not finished all courses, return false; otherwise true
        return finishedCount == numCourses;
    }
};