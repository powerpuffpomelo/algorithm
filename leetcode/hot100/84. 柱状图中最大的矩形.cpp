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
            while(stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            left_bound[i] = stk.size() ? stk.top() : -1;
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
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

// ###################################################### 版本2 ###################################################### //
// 单调栈+常数优化
// 如果存在几个连着同样高度的柱子，那么前几个的右边界求的不对（因为要求右边第一个小于自己的，前几个求的是小于等于自己的），但没关系，最后一个求的结果正确，只要留一个对的，就不影响最终结果
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_bound(n, 0), right_bound(n, n);  // 注意右边界初始化为n才是正确的！
        stack<int> stk;
        for(int i = 0; i < n; i++){
            while(stk.size() && heights[stk.top()] >= heights[i]){
                right_bound[stk.top()] = i;
                stk.pop();
            }
            left_bound[i] = stk.size() ? stk.top() : -1;
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int hh = heights[i];
            int ww = right_bound[i] - left_bound[i] - 1;
            ans = max(ans, hh * ww);
        }
        return ans;
    }
};