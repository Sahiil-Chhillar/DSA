class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto& ch : s) freq[ch]++;


        vector<pair<char,int>> v(freq.begin(),freq.end());
        sort(v.begin(),v.end(),[](pair<char,int>& a, pair<char,int>& b){return a.second>b.second;});

        string res = "";
        for(auto& [key,val] : v) res.append(val,key);

        return res;
    }
};

