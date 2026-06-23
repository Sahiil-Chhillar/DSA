class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges) adj[edge[0]].push_back({edge[1],edge[2]});
        
        vector<vector<long long>> dist(n, vector<long long>(k + 1, 1e18)); // {distance, node, consecutiveCount}

        priority_queue<tuple<long long, int, int>,vector<tuple<long long, int, int>>,greater<>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();
            if (d != dist[u][cnt]) continue;

            for (auto &[v, w] : adj[u]) {
                int newCnt;
                if (labels[v] == labels[u]) {
                    newCnt = cnt + 1;
                    if (newCnt > k) continue;
                }
                else newCnt = 1;

                long long nd = d + w;
                if (nd < dist[v][newCnt]) {
                    dist[v][newCnt] = nd;
                    pq.push({nd, v, newCnt});
                }
            }
        }

        long long ans = 1e18;
        for (int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        return ans == 1e18 ? -1 : ans;
    }
};