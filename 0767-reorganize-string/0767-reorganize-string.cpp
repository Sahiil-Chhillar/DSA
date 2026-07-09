class Solution {
public:
    string reorganizeString(string str) {
        unordered_map<char, int> freq;
        for (auto& ch : str) freq[ch]++;

        priority_queue<pair<int, char>> pq;
        for (auto& it : freq) pq.push({it.second, it.first});

        string res = "";

        pair<int, char> prev = {0, '@'};
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            res += current.second;
            current.first--;
            if (prev.first) pq.push(prev);

            prev = current;
        }

        if (res.size() != str.size()) return "";
        return res;
    }
};