// ###################################################### 版本1 ###################################################### //
// dp[i][j] 代表用j枚鸡蛋扔i次能测出的最大高度
int dp[10010][110];
class Solution {
public:
    int superEggDrop(int k, int n) {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i - 1][j - 1] + 1 + dp[i - 1][j];
            }
            if(dp[i][k] >= n) return i;
        }
        return -1;
    }
};

// ###################################################### 版本2 ###################################################### //
// dp[i][j]代表用i枚鸡蛋扔j次能测出的最大高度，相比版本1要麻烦一点而且高度需要ULL才能存
class Solution {
public:
    typedef unsigned long long ULL;
    int superEggDrop(int k, int n) {
        vector<vector<ULL>> dp(k + 1, vector<ULL>(n + 1));
        for(int i = 1; i <= n; i++) dp[1][i] = i;
        for(int i = 2; i <= k; i++){
            for(int f = 1; f <= n; f++){
                dp[i][f] = dp[i - 1][f - 1] + dp[i][f - 1] + 1;
            }
        }
        for(int f = 1; f <= n; f++){
            if(dp[k][f] >= n) return f;
        }
        return -1;
    }
};