// ###################################################### 版本2 ###################################################### //
// 还能再简化一点
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(auto& str : strs){
            int a = 0, b = 0;
            for(auto c : str){
                if(c == '0') a++;
                else b++;
            }
            for(int i = m; i >= a; i--){
                for(int j = n; j >= b; j--){
                    dp[i][j] = max(dp[i][j], dp[i - a][j - b] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

// ###################################################### 版本1 ###################################################### //
// dp，01背包
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<int> num_0(len, 0), num_1(len, 0);
        for(int i = 0; i < len; i++){
            for(char c : strs[i]){
                if(c == '0') num_0[i]++;
                else num_1[i]++;
            }
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= len; i++){
            for(int j = m; j >= num_0[i - 1]; j--){
                for(int k = n; k >= num_1[i - 1]; k--){
                    dp[j][k] = max(dp[j][k], dp[j - num_0[i - 1]][k - num_1[i - 1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};