// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> dp;
    int minimumPartition(string s, int k) {
        int n = s.size();
        string strk = to_string(k);
        int m = strk.size();
        dp = vector<int>(n + 1, 1e9);
        dp[0] = 0;
        s = ' ' + s;
        for(int i = 1; i <= n; i++){
            for(int l = 1; l <= m; l++){
                int j = i - l + 1;
                if(j <= 0) break;
                string temp = s.substr(j, l);
                if(l == m && temp > strk) break;
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        if(dp[n] == 1e9) return -1;
        return dp[n];
    }
};