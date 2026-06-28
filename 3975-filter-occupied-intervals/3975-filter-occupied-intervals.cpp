class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> merged;
        for (auto &x : occupiedIntervals) {
            if (merged.empty() || x[0] > merged.back()[1] + 1) merged.push_back(x);
            else merged.back()[1] = max(merged.back()[1], x[1]);
        }

        vector<vector<int>> ans;
        for(auto x : merged){
            int st = x[0];
            int end = x[1];
            if(end < freeStart || st > freeEnd){
                ans.push_back({st,end});
                continue;
            }
            if(st < freeStart) ans.push_back({st, freeStart - 1});
            if(end > freeEnd) ans.push_back({freeEnd + 1, end});
        }
        return ans;
    }
};