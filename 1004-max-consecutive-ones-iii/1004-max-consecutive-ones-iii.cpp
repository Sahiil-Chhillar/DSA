class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int currLength = 0;
        int flipped = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) flipped++;
            currLength++;
            while(flipped > k){
                if(nums[left] == 0) flipped--;
                left++;
                currLength--;
            }
            maxLength = currLength > maxLength ? currLength : maxLength;
        }

        return maxLength;
    }
};