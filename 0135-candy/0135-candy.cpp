class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> left(r.size());
        left[0] = 1;
        for(auto i = 1; i < r.size();i++) left[i] = (r[i] > r[i-1]) ? left[i-1] + 1 : 1;

        vector<int> right(r.size());
        right[r.size()-1] = 1;
        for(int i = r.size()- 2 ; i >=0 ;i--) right[i] = (r[i] > r[i+1]) ? right[i+1]+1 : 1;

        int totalCandy = 0;
        for(int i = 0; i < r.size();i++) totalCandy += max(right[i],left[i]);

        return totalCandy;
    }
};