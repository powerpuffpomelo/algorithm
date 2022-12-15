class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;
        int st = 0, max_len = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(i + 1 < n && s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                st = i, max_len = 2;   // 本题如果是直接记录字符串，则超时
            }
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(dp[i + 1][j - 1] && s[i] == s[j]){
                    dp[i][j] = 1;
                    st = i, max_len = len;
                }
            }
        }
        return s.substr(st, max_len);
    }
};