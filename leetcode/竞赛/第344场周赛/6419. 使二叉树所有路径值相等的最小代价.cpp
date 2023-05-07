// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int ans = 0;
    int dfs(int i, int n, vector<int>& cost){
        if(i * 2 > n) return cost[i - 1];
        int left = dfs(i * 2, n, cost), right = dfs(i * 2 + 1, n, cost);
        int mmax = max(left, right);
        ans += mmax * 2 - left - right;
        return mmax + cost[i - 1];
    }
    int minIncrements(int n, vector<int>& cost) {
        dfs(1, n, cost);
        return ans;
    }
};