class Solution {
public:
    int compress(vector<char>& chars) {
        string result = "";
        char prev = chars[0];
        int cnt = 1;
        for(int i = 1; i < chars.size();i++){
            if(chars[i] == prev) cnt++;
            else {
                result += prev;
                if(cnt > 1) result += to_string(cnt);
                cnt = 1;
                prev = chars[i]; 
            }
        }

        result += prev;
        if(cnt > 1) result += to_string(cnt);

        for(int i = 0 ; i < result.size();i++){
            chars[i] = result[i];
        }
        return result.size();
    }
};