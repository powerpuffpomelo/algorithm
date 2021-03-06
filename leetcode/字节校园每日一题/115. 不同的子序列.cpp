// 两个字符串的dp，一般二维状态，分别指向两个字符串的某个位置
// dp[i][j]表示，字符串s的前i位的子序列中，出现字符串t的前j位的数量。集合划分：s[i]参与匹配/s[i]不参与匹配
class Solution {
public:
    int numDistinct(string s, string t) {
        typedef unsigned long long ulld;
        int n = s.size(), m = t.size();
        vector<vector<ulld>> dp(n + 1, vector<ulld>(m + 1, 0));
        s = ' ' + s, t = ' ' + t;
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i - 1][j];
                if(s[i] == t[j]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};