class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> diff;
        string num = "";
        for(auto& i : word){
            if(isdigit(i)) num += i;
            else {
                if(!num.empty()){
                    while (num.size() > 1 && num[0] == '0') num.erase(0, 1);
                    diff.insert(num);
                } 
                num = "";
            }
        }
        if(!num.empty()){
            while (num.size() > 1 && num[0] == '0') num.erase(0, 1);
            diff.insert(num);
        }

        return diff.size();
    }
};