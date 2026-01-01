class Solution {
public:
    bool isPossible(int minDiff, vector<int>& p , int k){
        int pickedCnt = 1;
        int prevPicked = p[0];
        for(int i = 1; i < p.size();i++){
            if(p[i] - prevPicked >= minDiff) {
                pickedCnt++;
                prevPicked = p[i];
            }
            if(pickedCnt >= k) return true;
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int st = 0;
        int end = price[price.size()-1] - price[0];

        int maxT = 0;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(isPossible(mid,price,k)){
                maxT = mid;
                st = mid+1;
            }
            else end = mid -1;
        }

        return maxT;
    }
};