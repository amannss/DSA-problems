class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        map<int , vector<int>> adj;
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        vector<vector<int>> result(n);

        for (int s = 0; s < n; s++) {
            queue<int> q;
            vector<bool> visited(n, false);

            q.push(s);
            visited[s] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        result[v].push_back(s);
                        q.push(v);
                    }
                }
            }
        }
        return result;
    }
};
