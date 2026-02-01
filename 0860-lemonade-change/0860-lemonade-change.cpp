class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt_5 = 0;
        int cnt_10 = 0;
        for(auto& x : bills){
            if(x == 5) cnt_5++;
            else if(x == 10 && cnt_5) {
                cnt_5--;
                cnt_10++;
            }
            else{
                if(cnt_10 && cnt_5){
                    cnt_10--;
                    cnt_5--;
                }
                else if(cnt_5 >= 3) cnt_5 -= 3;
                else return false;
            }
        }

        return true;
    }
};