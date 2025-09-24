class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        // vector<int> inDegree(edges.size()+2,0);

        // for(auto& e : edges){
        //     inDegree[e[0]]++;
        //     inDegree[e[1]]++;
        // }

        // for(int i = 1 ; i <= edges.size()+1 ;i ++){
        //     if(inDegree[i] == edges.size()) return i;
        // }

        // return -1;


        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];
        return edges[0][1];
    }
};