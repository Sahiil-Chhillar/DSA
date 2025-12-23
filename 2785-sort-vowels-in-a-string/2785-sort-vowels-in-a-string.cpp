class Solution {
public:
    string sortVowels(string s) {
        vector<char>vowels;
        string ans="";
        for (auto& ch : s) {
            if (ch=='A'||ch=='E'||ch=='I'||
            ch=='O'||ch=='U'||ch=='a'||ch=='e'||
            ch=='i'||ch=='o'||ch=='u') vowels.push_back(ch);
        }
        sort(vowels.begin(),vowels.end());
        int k = 0;
        for(int i = 0 ; i < s.size();i++){
            if(s[i]=='A'||s[i]=='E' || s[i]=='I' || s[i]=='O' 
            || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' 
            || s[i]=='o'|| s[i]=='u') s[i] = vowels[k++];
        }
        return s;
    }
};