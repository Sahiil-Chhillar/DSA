class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int,vector<int>, greater<>> pq;

        for(auto& num : nums){
            pq.push(num);
            while(pq.size() > k) pq.pop();
        }

        long long sum = 0;

        while(!pq.empty()){
            if(pq.size() > mul) sum += pq.top();
            else sum += pq.top() * (mul-pq.size()+ 1);
            
            pq.pop();
        }

        return sum;
    }
};