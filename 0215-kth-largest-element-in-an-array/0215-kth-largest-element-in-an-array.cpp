class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // nlogn comlexity
        // priority_queue<int> pq;
        // for(auto& num : nums) pq.push(num);
        // while(k != 1) {
        //     pq.pop();
        //     k--;
        // }
        // return  pq.top();

        // nlogk complexity
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();
    }
};