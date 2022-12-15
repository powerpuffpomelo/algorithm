// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            if(s[i] != '0') dp[i] += dp[i - 1];
            if(i > 1 && (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};