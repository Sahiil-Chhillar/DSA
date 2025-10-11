// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = INT_MIN;
//         for(int i = 0 ; i < n ; i++){
//             // vector<int> currArray;
//             for(int j = i;j < n ; j++){
//                 // currArray.push_back(heights[j]);
//                 // int width = currArray.size();
//                 // int height = *min_element(currArray.begin(),currArray.end());
//                 int width = j - i + 1;
//                 int height = (width == 1) ? heights[j] : (height < heights[j]) ? height: heights[j]; 
//                 maxArea = maxArea < height * width ? height*width : maxArea ;
//             }
//         }
//         return maxArea;
//     }
// };



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        vector<int> l(n,0);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            l[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        vector<int> r(n,0);
        st = stack<int>();
        for(int i = n-1;i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            r[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0 ;  i< n ;i++){
            int currArea = heights[i] * (r[i] - l[i] -1);
            maxArea = max(currArea , maxArea);
        }

        return maxArea;
    }
};