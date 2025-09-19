class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;r--;
        }
        return true;
    }

    void f(int st,string& s,vector<vector<string>>& result,vector<string>& currPar){
        if(st == s.size()) {
            result.push_back(currPar);
            return;
        }

        for(int end = st ; end < s.size();end++){
            if(isPalindrome(s,st,end)){
                currPar.push_back(s.substr(st,end - st + 1));
                f(end+1,s,result,currPar);
                currPar.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currPar;
        f(0,s,result,currPar);
        return result;
    }
};