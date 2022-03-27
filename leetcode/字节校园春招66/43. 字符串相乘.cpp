// ###################################################### 版本1 ###################################################### //
// 本天才解法:D
class Solution {
public:
    vector<int> dp;
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> a, b;
        for(int i = n - 1; i >= 0; i--) a.push_back(num1[i] - '0');
        for(int i = m - 1; i >= 0; i--) b.push_back(num2[i] - '0');
        dp.resize(n + m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i + j] += a[i] * b[j];
            }
        }
        string ans;
        int t = 0;
        for(int i = 0; i < n + m; i++){
            dp[i] += t;
            t = dp[i] / 10;
            dp[i] %= 10;
            ans += dp[i] + '0';
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > 1 && ans[0] == '0') ans = ans.substr(1);
        return ans;
    }
};