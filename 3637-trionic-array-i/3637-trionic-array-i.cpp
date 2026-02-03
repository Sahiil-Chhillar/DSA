class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        
        while(idx < n-1 && nums[idx] < nums[idx+1]) idx++;
        if(idx == 0 || idx == n-1) return false;

        while(idx < n-1 && nums[idx] > nums[idx+1]) idx++;
        if(idx == 0 || idx == n-1) return false;

        while(idx < n-1 && nums[idx] < nums[idx+1]) idx++;

        return idx == n-1;
    }
};