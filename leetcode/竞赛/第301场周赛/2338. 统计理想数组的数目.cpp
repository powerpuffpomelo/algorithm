// ###################################################### 版本2 ###################################################### //
// dp
class Solution {
public:
    int idealArrays(int n, int m) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(m + 1, vector<int>(15));   // dp[i][j]: 以i为结尾，数组中不同数字的长度为j，的方案数
        for (int i = 1; i <= m; i ++ ) dp[i][1] = 1;

        for (int j = 1; j < 14; j ++ )
            for (int i = 1; i <= m; i ++ )
                for (int k = 2; k * i <= m; k ++ )
                    dp[k * i][j + 1] = (dp[k * i][j + 1] + dp[i][j]) % MOD;

        vector<vector<int>> C(n, vector<int>(15));  // 组合数
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j <= i && j <= 14; j ++ )
                if (!j) C[i][j] = 1;
                else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;

        int res = 0;
        for (int i = 1; i <= m; i ++ )
            for (int j = 1; j <= 14 && j <= n; j ++ )
                res = (res + (long long)dp[i][j] * C[n - 1][j - 1]) % MOD;
        return res;
    }
};

// ###################################################### 版本1 ###################################################### //
// dfs
class Solution {
public:
    int n, m;
    int ans = 0;
    const int MOD = 1e9 + 7;
    vector<vector<int>> C;
    
    void dfs(int u, int cnt) {
        ans = (ans + C[n - 1][cnt - 1]) % MOD;
        if (cnt < n) {
            for (int i = 2; i * u <= m; i ++ )
                dfs(i * u, cnt + 1);
        }
    }
    
    int idealArrays(int n, int m) {
        this->n = n, this->m = m;
        C = vector<vector<int>>(n, vector<int>(20));
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < 20 && j <= i; j ++ )
                if (!j) C[i][j] = 1;
                else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        
        for (int i = 1; i <= m; i ++ )
            dfs(i, 1);
        
        return ans;
    }
};