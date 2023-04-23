// ###################################################### 版本1 ###################################################### //
// dp[i] 前i本书填充的最小高度
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int w = 0, h = 0;
            for(int j = i; j >= 1; j--){  // 根据当前层书架有多少本书 来划分集合
                w += books[j - 1][0];
                if(w > shelfWidth) break;
                h = max(h, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + h);
            }
        }
        return dp[n];
    }
};