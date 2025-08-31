class Solution {
public:
    int f(int i,int j,string& str1, string& str2,vector<vector<int>>& dp){
        if(i == str1.size() || j == str2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int matched = 0;
        if(str1[i] == str2[j]) matched = 1 + f(i+1,j+1,str1,str2,dp);
        int notMatched = max(
            f(i,j+1,str1,str2,dp),
            f(i+1,j,str1,str2,dp)
        );

        return dp[i][j] = max(matched,notMatched);
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        int cl = f(0,0,str1,str2,dp);

        string cStr = "";
        int m = str1.size(),n = str2.size(),i = 0,j=0;
        while( i < m && j < n){
            if(str1[i] == str2[j]){
                cStr.push_back(str1[i]);
                i++;j++;
            }else{
                if(dp[i][j+1] > dp[i+1][j]) j++;
                else i++;
            }  
        }
        
        cout<<"Length :- " << cl << " String :- " << cStr << endl;

        string scSeq = "";
        i =0;j=0;
        int k = 0;
        while(i < m && j < n && k < cl){
            if(str1[i] != cStr[k]) {
                scSeq.push_back(str1[i]);
                i++;
            }
            if(str2[j] != cStr[k]){
                scSeq.push_back(str2[j]);
                j++;
            }
            if(str1[i] == cStr[k] && str2[j] == cStr[k]){
                scSeq.push_back(cStr[k]);
                k++;i++;j++;
            }
        }
        while(i<m) {
            scSeq.push_back(str1[i]);
            i++;
        }
        while(j<n){
            scSeq.push_back(str2[j]);
            j++;
        }
        cout<<"ANSWER :- "<< scSeq << endl;
        return scSeq;
    }
};