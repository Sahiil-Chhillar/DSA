class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for(auto& p : patterns){
            if(word.contains(p)) cnt++;
        }

        return cnt;
    }
};