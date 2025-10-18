class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0 ; i < s.size();i++){
            vector<int> freq(26,0);
            for(int j = i;j<s.size();j++){
                freq[s[j]-'a']++;
                int maxFreq = 0;
                int minFreq = 1e9;
                for(int k = 0 ; k < 26;k++){
                    if (freq[k] > 0){
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    } 
                }
                sum += maxFreq - minFreq;
            }
        }
        return sum;
    }
};