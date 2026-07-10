class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> countStack;

        string currString = "";
        int currNum = 0;

        for (auto& ch : s) {
            if (isdigit(ch)) currNum = currNum * 10 + (ch - '0');
            else if (ch == '[') {
                stringStack.push(currString);
                countStack.push(currNum);

                currString = "";
                currNum = 0;
            }
            else if (ch == ']') {
                int cnt = countStack.top();
                countStack.pop();
                string prevStr = stringStack.top();
                stringStack.pop();

                for (int i = 0; i < cnt; i++) prevStr += currString;
                currString = prevStr;
            }
            else currString.push_back(ch);
        }
        return currString;
    }
};