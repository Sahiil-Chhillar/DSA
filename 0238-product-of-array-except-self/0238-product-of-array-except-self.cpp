class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int pos = 0;
        // int size = nums.size();
        // vector<int> result(size);
        // for(int i = 0; i< size; i++ ){
        //     int product = 1;
        //     for(int j = 0;j<size;j++){
        //         if(j != pos){
        //             product *= nums[j];
        //         }
        //     }
        //     result[pos++] = product;
        // }
        // return result;
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};