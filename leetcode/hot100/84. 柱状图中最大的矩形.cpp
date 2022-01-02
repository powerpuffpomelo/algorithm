// ###################################################### 版本1 ###################################################### //
// 我的初版，单调栈
// 降低时间复杂度，可以思考什么能事先算好存起来，空间换时间
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_bound(n, 0), right_bound(n, 0);
        stack<int> stk;
        for(int i = 0; i < n; i++){
            while(stk.size() && heights[i] <= heights[stk.top()]) stk.pop();
            left_bound[i] = stk.size() ? stk.top() : -1;
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(stk.size() && heights[i] <= heights[stk.top()]) stk.pop();
            right_bound[i] = stk.size() ? stk.top() : n;
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int hh = heights[i];
            int ww = right_bound[i] - left_bound[i] - 1;  // 每个柱的高度可以延展多宽
            ans = max(ans, hh * ww);
        }
        return ans;
    }
};