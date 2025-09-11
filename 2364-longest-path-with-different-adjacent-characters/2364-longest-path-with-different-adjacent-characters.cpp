class Solution {
public:
    int f(int currNode,string& s,vector<vector<int>>& tree,int& ans){
        int lPath= 0, slPath= 0;
        for(auto& childNode : tree[currNode]){
            int childLen = f(childNode,s,tree,ans);
            if(s[currNode] == s[childNode]) continue;
            if(lPath < childLen) {
                slPath = lPath;
                lPath = childLen;
            }
            else if(slPath < childLen) slPath = childLen;
        }

        ans = max(1+lPath+slPath,ans);
        return 1 + lPath;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        for(int i = 1 ; i < n;i++){
            tree[parent[i]].push_back(i);
        }
        int ans = 1;
        f(0,s,tree,ans);
        return ans;
    }
};