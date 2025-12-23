// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int>freq;
//         for(auto& num : nums) freq[num]++;

//         vector<pair<int,int>> mostK; // {freq,num}
//         for(auto& f : freq) mostK.push_back({f.second,f.first});
//         sort(mostK.begin(),mostK.end());

//         vector<int> ans;
//         for(auto& p : mostK) ans.push_back(p.second);
        
//         return vector<int>(ans.end()-k,ans.end());
//     }
// };

typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto& num : nums) freq[num]++;

        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto& f : freq){
            pq.push({f.second,f.first});
            if(pq.size()> k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};