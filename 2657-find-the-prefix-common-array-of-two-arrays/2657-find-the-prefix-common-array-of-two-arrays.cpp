class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans;
        int value=0;
        vector<int>freq(n,0);
        for(int i=0;i<n;i++){
            freq[A[i]-1]++;
            freq[B[i]-1]++;
            if(freq[A[i]-1]==2) value++;
            if(B[i]!= A[i] && freq[B[i]-1] == 2) value++;
            ans.push_back(value);
        }
        return ans;
    }
};