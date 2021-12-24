class Solution {
    int dp[510][510];

public:
    int minDistance(string word1, string word2) {
        //23.25
        int l1 = word1.size(), l2 = word2.size();
        for(int i = 1; i <= l1; i++) dp[i][0] = i;
        for(int j = 1; j <= l2; j++) dp[0][j] = j;
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
            }
        }
        return dp[l1][l2];
    }
};