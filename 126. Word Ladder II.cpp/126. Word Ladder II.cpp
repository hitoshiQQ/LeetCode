class Solution {
public:
    void backtrack(string cur, string& endWord, unordered_map<string, unordered_set<string>>& graph,
        vector<string>& path, vector<vector<string>>& paths) {
        //cout << "cur: " << cur << endl;
        if (cur == endWord) {
            paths.push_back(path);
        }
        else {
            //cout << "neighbors: " << graph[cur].size() << endl;
            for (const string& nei : graph[cur]) {
                path.push_back(nei);
                backtrack(nei, endWord, graph, path, paths);
                path.pop_back();
            }
        }
    };

    bool visitLevel(unordered_set<string>& words, unordered_map<string, unordered_set<string>>& graph,
        queue<string>& q, unordered_set<string>& visited, unordered_set<string>& visited_other, bool reversed) {
        int levelSize = q.size();
        bool foundEnd = false;
        unordered_set<string> visiting;

        //visited: visited node for previous levels
        //visiting: the nodes visit in current level

        while (levelSize-- > 0) {
            string cur = q.front(); q.pop();
            //cout << cur << " : ";

            string nei = cur;

            for (int i = 0; i < cur.size(); ++i) {
                char oldC = nei[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == oldC) continue;
                    nei[i] = c;

                    if (words.find(nei) != words.end()) {
                        if (visited_other.find(nei) != visited_other.end()) {
                            //cout << "found end ";
                            foundEnd = true;
                        }

                        //if nei isn't in previous levels
                        if (visited.find(nei) == visited.end()) {
                            /*
                            Here we don't mark "nei" as "visited",
                            because we want that "nei" can be visited by
                            multiple nodes in current level!!!
                            */
                            visiting.insert(nei);
                            q.push(nei);

                            if (!reversed) {
                                graph[cur].insert(nei);
                            }
                            else {
                                graph[nei].insert(cur);
                            }
                            //cout << nei << " ";
                        }
                    }

                }
                nei[i] = oldC;
            }
            //cout << endl;
        }

        //the nodes in visiting are actually visited in current level
        visited.insert(visiting.begin(), visiting.end());

        return foundEnd;
    };

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> graph;
        int n = words.size();

        if (words.find(endWord) == words.end()) return vector<vector<string>>();

        //cout << "word: ";
        //for(const string& word : words){
        //    cout << word << " ";
        //}
        //cout << endl;

        bool foundEnd = false;
        queue<string> q1, q2;
        unordered_set<string> visited1, visited2;
        queue<string> qnext;
        bool reversed = false;

        q1.push(beginWord);
        q2.push(endWord);
        visited1.insert(beginWord);
        visited2.insert(endWord);

        while (!q1.empty() && !q2.empty() && !foundEnd) {
            if (q1.size() < q2.size()) {
                //cout << "forward: " << endl;
                foundEnd = visitLevel(words, graph, q1, visited1, visited2, false);
            }
            else {
                //cout << "backward: " << endl;
                foundEnd = visitLevel(words, graph, q2, visited2, visited1, true);
            }
        }

        //for(auto p : graph){
        //    cout << p.first << " -> ";
        //    for(const string& nei : p.second){
        //        cout << nei << " ";
        //    }
        //    cout << endl;
        //}

        vector<string> path = { beginWord };
        vector<vector<string>> paths;

        backtrack(beginWord, endWord, graph, path, paths);

        return paths;
    }
};