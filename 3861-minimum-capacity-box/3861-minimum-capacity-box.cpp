class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minIdx = -1;
        int minCap = 1e9;
        for(int i = 0 ; i < capacity.size();i++){
            if(capacity[i] >= itemSize && capacity[i] < minCap){
                minIdx = i;
                minCap = capacity[i];
            }
        }
        return minIdx;
    }
};