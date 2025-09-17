class Solution {
public:
    int myAtoi(string s) {
        int st = 0;
        int n = s.length();

        while(st < n && s[st] == ' ') st++;

        int sign = 1;
        if(st < n && (s[st] == '+' || s[st] == '-')){
            if(s[st] == '-') sign = -1;
            st++;
        }

        long result = 0;
        while(st < n && isdigit(s[st])){
            result = result * 10 + (s[st] - '0');
            st++;


            if(result * sign >= INT_MAX) return INT_MAX;
            if(result * sign <= INT_MIN) return INT_MIN;
        }


        return (int) (result*sign);
    }
};