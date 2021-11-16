class Solution {
public:
    vector<int> adj[10001];
    bool visited[10001];
    bool finished[10001];

    bool dfs(int cur) {
        if (visited[cur]) return false;
        if (finished[cur]) return true;

        visited[cur] = true;
        for (const auto &nxt: adj[cur]) {
            if (!dfs(nxt)) {
                return false;
            }
        }
        visited[cur] = false;
        finished[cur] = true;

        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        for (const auto &p: prerequisites) {
            adj[p[1]].emplace_back(p[0]);
        }

        for (int k = 0; k < numCourses; k++) {
            if (!dfs(k)) {
                return false;
            }
        }
        return true;
    }
};
