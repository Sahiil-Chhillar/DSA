class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i = nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if(!st.empty()) mp[nums2[i]] = st.top();
            else mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }

        vector<int> res;
        for(auto& num : nums1){
            res.push_back(mp[num]);
            // if(mp.find(num) != mp.end()) res.push_back(mp[num]);
        }
        return res;
    }
};