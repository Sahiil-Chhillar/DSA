/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *Result = (int*)malloc(sizeof(int) * nums1Size);
    int resultSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if(nums1[i]==nums2[j]){
                // yha pr hme check krna padega ki number already toh present nhi h 
                int check = 0;
                for(int k = 0 ; k < resultSize; k++){
                    if(Result[k]==nums1[i]){
                        check = 1;
                        break;
                    }
                }
                if(!check){
                    Result[resultSize]=nums1[i];
                    resultSize++;
                }
            }
        }
    }
    *returnSize = resultSize;
    return Result;
}