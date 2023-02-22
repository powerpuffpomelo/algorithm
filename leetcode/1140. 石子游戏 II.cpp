// ###################################################### 版本1 ###################################################### //
/*
dp博弈论：dp[i][j]代表，
集合：目前轮到的一方获得的石子状态是：还剩下从第i堆到第n堆石子，且可以取的数量上限M=j。
属性：目前轮到的一方可以获得的石子最大值
状态计算：列举准备取的所有可能的堆数，看那种堆数 对方能取的最少。
*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 1));
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++){
            s[i] = s[i - 1] + piles[i - 1];
        }
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                for(int k = 1; i + k - 1 <= n && k <= 2 * j; k++){   // k代表目前轮到的一方准备取多少堆石子
                    dp[i][j] = max(dp[i][j], s[n] - s[i - 1] - dp[i + k][max(k, j)]);  // 剩下的数量，减去对方在可以取的最大数量
                }
            }
        }
        return dp[1][1];
    }
};