class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> bl(brokenLetters.begin(),brokenLetters.end());

        int cnt = 0;
        bool flag = true;

        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {  
                if (flag) cnt++;  
                flag = true;
            } else {
                if (bl.find(text[i]) != bl.end()) {
                    flag = false;
                }
            }
        }
        if(flag) cnt++;

        return cnt;
    }
};