class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l < r){
            if(s[l] == s[r]){
                while(l < r && s[l] == s[l+1]) l++;
                while(l < r && s[r] == s[r-1]) r--;

                l++;
                r--;
            }
            else return r-l+1;
        }

        return l == r ? 1 : 0;
    }
};