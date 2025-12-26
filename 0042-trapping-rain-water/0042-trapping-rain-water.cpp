class Solution {
public:
    int trap(vector<int>& arr) {
        int leftMax = 0;
        int rightMax = 0;
        int totalW = 0;
        
        int st = 0;
        int end = arr.size()-1;
        
        while(st <= end){
            if(arr[st] < arr[end]){
                if(leftMax > arr[st]) totalW += leftMax - arr[st];
                else leftMax = arr[st];
                
                st++;
            }
            else{
                if(rightMax > arr[end]) totalW += rightMax - arr[end];
                else rightMax = arr[end];
                
                end--;
            }
        }
        
        return totalW;
    }
};