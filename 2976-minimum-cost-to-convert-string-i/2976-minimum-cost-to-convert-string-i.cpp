// MY Code 
// class Solution {
// public:
//     typedef pair<char,int> pci;
//     const long long INF = 1e18;
//     vector<long long> dijkstra(char src,unordered_map<char,vector<pci>>& adjL){
//         priority_queue<pair<long long,char>,vector<pair<long long,char>>,greater<>> pq;
//         vector<long long> dist(26,INF);

//         dist[src -'a'] = 0;
//         pq.push({0,src});
//         while(!pq.empty()){
//             auto [d,u] = pq.top();
//             pq.pop();

//             if(d > dist[u-'a']) continue;

//             for(auto& edge : adjL[u]){
//                 char v = edge.first;
//                 int w = edge.second;
//                 if(dist[v-'a'] > d + w){
//                     dist[v-'a'] = d+w;
//                     pq.push({dist[v-'a'],v});
//                 }
//             }
//         }
//         return dist;
//     }
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         unordered_map<char,vector<pci>> adjL;
//         for(int i = 0; i < original.size();i++) adjL[original[i]].push_back({changed[i],cost[i]});
        
//         unordered_map<char,vector<long long>> memo;
//         long long ans =0;

//         for(int i = 0; i< source.size();i++){
//             char s = source[i];
//             char t = target[i];
//             if(s == t) continue;
//             if(memo.find(s) == memo.end()) memo[s] = dijkstra(s,adjL);
//             if(memo[s][t-'a'] == INF) return -1;
//             ans += memo[s][t-'a'];
//         }

//         return ans;
//     }
// };

// OPTIMAL CODE uisng floyed warshell alggo 

class Solution {
public:
    long long minimumCost(string source, string target,
 vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dist[26][26];
        const long long INF = 1e14;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (size_t i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < 26; ++j) {
                    if (dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        int n = source.length();

        for (int i = 0; i < n; ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (u == v) continue;
            if (dist[u][v] == INF) return -1;
            totalCost += dist[u][v];
        }

        return totalCost;
    }
};