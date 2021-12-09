// 单调栈

// ###################################################### 版本1 ###################################################### //
// 从后向前遍历，单调栈维护的是待选择的答案篮子，每经过一个元素都能得到解
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
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


// ###################################################### 版本2 ###################################################### //
// 从前向后遍历，单调栈维护的是待回答的元素篮子，每经过一个元素都试图回答栈里能回答的问题

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> ans(length);
        stack<int> st;
        for(int i = 0; i < length; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};