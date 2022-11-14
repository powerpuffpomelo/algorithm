// ###################################################### 版本2 ###################################################### //
// 根本无需搜索
class Solution {
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.resize(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

// ###################################################### 版本1 ###################################################### //
// 记忆化搜索
class Solution {
public:
    vector<int> dp;
    int dfs(int x){
        if(dp[x]) return dp[x];
        int s = 0;
        for(int i = 0; i < x; i++){
            int left = dfs(i);
            int right = dfs(x - i - 1);
            s += left * right;
        }
        return dp[x] = s;
    }
    int numTrees(int n) {
        dp.resize(n + 1);
        dp[0] = dp[1] = 1;
        return dfs(n);
    }
};