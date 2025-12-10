class Solution {
public:
    void sortColors(vector<int>& arr) {
        // int temp[] = {0, 0, 0};
        // for (int i = 0; i < arr.size(); i++) {
        //     temp[arr[i]]++;
        // }
        // int index = 0;
        // for (int i = 0; i < 3; i++) {
        //     while (temp[i] > 0) {
        //         arr[index++] = i;
        //         temp[i]--;
        //     }
        // }

        int i = 0, j = 0, k = arr.size() - 1;
        while(j <= k){
            if(arr[j] == 0) {
                swap(arr[i],arr[j]);
                i++;j++;
            }
            else if(arr[j] == 1) j++;
            else{
                swap(arr[j],arr[k]);
                k--;
            }
        }
    }
};