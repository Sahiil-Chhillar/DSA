class Solution {
public:
    int findClosest(int x, int y, int z) {
        int minX = abs(x-z);
        int minY = abs(y-z);
        return minX - minY == 0 ? 0 : (minX < minY) ? 1 : 2;
    }
};