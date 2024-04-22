class Solution {
public:
    // Variables
    unordered_set<string> deadendsSet;
    string start;
    string target;

    // Tries to unlock the lock by turing the wheels, avoiding deadends and finding
    // shortest path to the target combination
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        // Populating the deadends set for quick lookups
        for (const auto& d : deadends) {
            deadendsSet.insert(d);
        }

        // The start point is a deadend
        if (deadendsSet.count("0000")) {
            return -1;
        }

        this->start = "0000";
        this->target = target;

        // Perform a bidirectional bfs to find the shortest path
        return bidirectionalBFS();
    }

    // Bidirectional BFS to find the shortest path
    int bidirectionalBFS() {

        // Maps from string to minimum steps needed from start
        unordered_map<string, int> m1;

        // Maps from string to minimum steps needed from target
        unordered_map<string, int> m2;

        // Init
        m1[start] = 0;
        m2[target] = 0;

        queue<string> q1 {{start}};
        queue<string> q2 {{target}};

        while (!q1.empty() && !q2.empty()) {
            // Chose the queue with fewer elemets to extend
            int t = (q1.size() <= q2.size()) ? extends(m1, m2, q1) : extends(m2, m1, q2);

            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    // Extends the search from one queue, using other queue to check for a meeting point
    int extends(unordered_map<string, int>& visitedFromOneSide, unordered_map<string, int>& visitedFromOtherSide,
        queue<string>& queueToExtend) {
        for (int n = queueToExtend.size(); n > 0; --n) {
            string currentPosition = queueToExtend.front();
            int step = visitedFromOneSide[currentPosition];
            queueToExtend.pop();

            for (const string& nextPosition : getNextPosition(currentPosition)) {
                if (deadendsSet.count(nextPosition) || visitedFromOneSide.count(nextPosition)) {
                    continue;
                }

                if (visitedFromOtherSide.count(nextPosition)) {
                    // if we find the current nextpos in the other sides visited map, we found the shortest path
                    return step + 1 + visitedFromOtherSide[nextPosition];
                }
                // Update the step count for next pos
                visitedFromOneSide[nextPosition] = step + 1;
                queueToExtend.push(nextPosition);
            }
        }
        return -1;
    }

    // Generates all possible combinations that can be reached from the current state in one move
    vector<string> getNextPosition(string& currentPosition) {
        vector<string> possibleNextPositions;
        for (int j = 0; j < 4; ++j) {
            char originalCharacter = currentPosition[j];

            // Turn wheel down
            currentPosition[j] = originalCharacter == '0' ? '9' : (char)(originalCharacter - 1);
            possibleNextPositions.push_back(currentPosition);

            // Turn wheel up
            currentPosition[j] = originalCharacter == '9' ? '0' : (char)(originalCharacter + 1);
            possibleNextPositions.push_back(currentPosition);

            // Reset the character to the original one
            currentPosition[j] = originalCharacter;
        }
        return possibleNextPositions;
    }
};