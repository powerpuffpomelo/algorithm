// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    vector<vector<int>> s;
    int get(int x1, int y1, int x2, int y2){
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int n = matrix.size(), m = matrix[0].size();
        s = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                set<int> se;
                se.insert(0);
                for(int k = 1; k <= n; k++){
                    int si = get(1, i, k, j);
                    auto it = se.lower_bound(si - K);
                    if(it != se.end()) ans = max(ans, si - *it);
                    se.insert(si);
                }
            }
        }
        return ans;
    }
};