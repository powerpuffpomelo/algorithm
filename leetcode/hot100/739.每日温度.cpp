// 单调栈

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 15.25
        stack<int> st;
        vector<int> ans;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top() - i);
            st.push(i);
        }
        reverse(ans.begin(), ans.end());   // #include <algorithm>
        return ans;
    }
};