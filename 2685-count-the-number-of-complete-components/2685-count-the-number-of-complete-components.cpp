class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visitedNode(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (visitedNode[i]) continue;

            queue<int> q;
            q.push(i);
            visitedNode[i] = true;

            int nodes = 0;
            int edgeCount = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                nodes++;
                edgeCount += adj[u].size();

                for (int v : adj[u]) {
                    if (!visitedNode[v]) {
                        visitedNode[v] = true;
                        q.push(v);
                    }
                }
            }

            edgeCount /= 2; // bcs undirected Graph so each node is counted twice in BFS
            if (edgeCount == nodes * (nodes - 1) / 2) cnt++;
        }

        return cnt;
    }
};