class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";
        // int cnt = 0;
        // string ans = "";
        // for(int i = 0 ; i+1 < num.size();i++){
        //     if(num[i] < num[i+1]) {
        //         ans += num[i];
                
        //     }
        //     cnt++;
        //     if(cnt >= k){
        //         ans += num.substr(i+1);
        //         break;
        //     } 
        // }
        // return ans;

        stack<char> st;
        for(auto& ch : num){
            while(!st.empty() && k>0 && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        

        string ans = "";
        while(!st.empty()){
            ans.insert(ans.begin(),st.top());
            st.pop();
        }
        
        int i = 0;
        while(ans[i] == '0') i++;
        ans = ans.substr(i);
        while(k != 0 && !ans.empty()){
            ans.pop_back();
            k--;
        }
        return ans.size() != 0 ? ans : "0";
    }
};