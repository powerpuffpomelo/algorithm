// ###################################################### 版本2 ###################################################### //
// dp巧妙解法，类似完全背包
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(j < m && p[j + 1] == '*') continue;
                if(i && p[j] != '*'){
                    dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }else if(p[j] == '*'){
                    dp[i][j] = dp[i][j - 2] || i && dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'); // 这里注意i != 0
                }
            }
        }
        return dp[n][m];
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的麻烦思路
class Solution {
public:
    bool isMatch(string s, string p) {
        s = ' ' + s, p = ' ' + p;
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(j + 1 < m && p[j + 1] == '*') continue;
                if(p[j] >= 'a' && p[j] <= 'z'){
                    if(i && dp[i - 1][j - 1] && s[i] == p[j]) dp[i][j] = 1;
                }else if(p[j] == '.') dp[i][j] = i ? dp[i - 1][j - 1] : 0;
                else{
                    int k = i;
                    dp[i][j] = dp[k][j - 2];
                    if(p[j - 1] != '.'){
                        while(k > 0 && !dp[i][j] && s[k] == p[j - 1]){
                            k--;
                            dp[i][j] = dp[k][j - 2];
                        }
                    }else{
                        while(!dp[i][j] && k > 0){
                            k--;
                            dp[i][j] = dp[k][j - 2];
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};