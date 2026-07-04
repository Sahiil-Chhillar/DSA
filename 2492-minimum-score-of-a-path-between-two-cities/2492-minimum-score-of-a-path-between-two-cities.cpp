class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& e : roads){
            graph[e[0]].push_back({e[1],e[2]});// {u-> (v,w)}
            graph[e[1]].push_back({e[0],e[2]});
        }

        int miniScore = 1e9;
        queue<int> q;
        q.push(1);

        vector<bool> visited(n+1,false);
        visited[1] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& [nbr,score] : graph[node]){
                miniScore = miniScore < score ? miniScore : score;
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                } 
            }
        }

        return miniScore;
    }
};