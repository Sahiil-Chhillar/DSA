class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()% 2 != 0) return {};

        unordered_map<int,int> freq;
        for(auto& num : changed) freq[num]++;

        vector<int> org;
        sort(changed.begin(),changed.end());
        for(auto& num : changed){
            if(freq[num] == 0) continue;
            if(freq[num * 2] == 0) return {};

            org.push_back(num);
            freq[num]--;
            freq[num*2]--;
        }
        return org;
    }
};