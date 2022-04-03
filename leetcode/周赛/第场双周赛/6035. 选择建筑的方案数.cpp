// 会超时
class Solution {
public:
    // dp[i][j][k] 前i栋建筑，已经选择j个不一样的建筑，且最后一个选择的为k，总的方案数  j取值<=3, k = 0/1
    // dp[i][j][k] = dp[i - 1][j][k] 不选 + 看看选第i个：dp[i - 1][j - 1][1 - k]
    // 
    long long numberOfWays(string s) {
        s = ' ' + s;
        int n = s.size();
        if(n <= 3) return 0;
        int check = 0;
        for(int i = 1; i < n;){
            check++;
            while(i < n && s[i] == s[i + 1]) i++;
            i++;
        }
        //cout << check <<endl;
        if(check < 3) return 0;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(4, vector<long long>(2)));
        dp[0][0][0] = dp[0][0][1] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= 3; j++){
                dp[i][j][0] = dp[i - 1][j][0] + ((j && s[i] == '0') ? dp[i - 1][j - 1][1] : 0);
                dp[i][j][1] = dp[i - 1][j][1] + ((j && s[i] == '1') ? dp[i - 1][j - 1][0] : 0);
            }
        }
        return dp[n - 1][3][0] + dp[n - 1][3][1];
    }
};