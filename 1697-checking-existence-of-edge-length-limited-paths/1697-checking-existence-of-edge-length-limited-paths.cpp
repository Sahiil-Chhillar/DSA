class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i;
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) { return a[2] < b[2]; });

        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }

        sort(q.begin(), q.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        vector<bool> ans(queries.size());
        int j = 0;
        for (auto& query : q) {
            int u = query[0];
            int v = query[1];
            int limit = query[2];
            int idx = query[3];

            while (j < edgeList.size() && edgeList[j][2] < limit) {
                unionSet(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[idx] = (find(u) == find(v));
        }
        return ans;
    }
};