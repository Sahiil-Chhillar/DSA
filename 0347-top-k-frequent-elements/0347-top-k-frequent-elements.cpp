class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto& num : nums) freq[num]++;

        vector<pair<int,int>> mostK; // {freq,num}
        for(auto& f : freq) mostK.push_back({f.second,f.first});
        sort(mostK.begin(),mostK.end());

        vector<int> ans;
        for(auto& p : mostK) ans.push_back(p.second);
        
        return vector<int>(ans.end()-k,ans.end());
    }
};