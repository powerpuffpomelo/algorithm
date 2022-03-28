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