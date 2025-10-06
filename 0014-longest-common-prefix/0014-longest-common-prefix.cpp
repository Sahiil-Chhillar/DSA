class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for(int i = 1 ; i < strs.size();i++){
            while(strs[i].find(res) != 0){
                res.pop_back();
                if(res.size() == 0) return "";
            }
        }
        return res;
    }
};