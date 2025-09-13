class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Freq(26,0);
        for(auto& c : s1) s1Freq[c-'a']++;

        int n = s1.size();

        for(int i = 0; i < s2.size();i++){
            vector<int> windowFreq(26,0);
            string currString = s2.substr(i, n);
            for(auto& c : currString) windowFreq[c-'a']++;

            if(s1Freq == windowFreq) return true;
        }

        return false;
    }
};