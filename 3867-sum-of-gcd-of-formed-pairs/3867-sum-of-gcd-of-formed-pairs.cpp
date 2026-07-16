class Solution {
public:
    int gcd(int a,int b) {
        return b == 0 ? a : gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {

        vector<int> prefixGCD;
        int currMax = -1e9;
        for(auto& num : nums){
            currMax = currMax > num ? currMax : num;
            prefixGCD.push_back(gcd(currMax,num));
        }

        sort(prefixGCD.begin(),prefixGCD.end());
        int st = 0;
        int end = prefixGCD.size()-1;
        long long sum = 0;
        while(st < end){
            sum += gcd(prefixGCD[st],prefixGCD[end]);
            st++;
            end--;
        }

        return sum;
    }
};