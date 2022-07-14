// ###################################################### 版本2 ###################################################### //
// dp
class Solution {
public:
    int idealArrays(int n, int m) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> f(m + 1, vector<int>(15));
        for (int i = 1; i <= m; i ++ ) f[i][1] = 1;

        for (int j = 1; j < 14; j ++ )
            for (int i = 1; i <= m; i ++ )
                for (int k = 2; k * i <= m; k ++ )
                    f[k * i][j + 1] = (f[k * i][j + 1] + f[i][j]) % MOD;

        vector<vector<int>> C(n, vector<int>(15));
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j <= i && j <= 14; j ++ )
                if (!j) C[i][j] = 1;
                else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;

        int res = 0;
        for (int i = 1; i <= m; i ++ )
            for (int j = 1; j <= 14 && j <= n; j ++ )
                res = (res + (long long)f[i][j] * C[n - 1][j - 1]) % MOD;
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
    vector<vector<int>> f;
    
    void dfs(int u, int cnt) {
        ans = (ans + f[n - 1][cnt - 1]) % MOD;
        if (cnt < n) {
            for (int i = 2; i * u <= m; i ++ )
                dfs(i * u, cnt + 1);
        }
    }
    
    int idealArrays(int n, int m) {
        this->n = n, this->m = m;
        f = vector<vector<int>>(n, vector<int>(20));
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < 20 && j <= i; j ++ )
                if (!j) f[i][j] = 1;
                else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
        
        for (int i = 1; i <= m; i ++ )
            dfs(i, 1);
        
        return ans;
    }
};