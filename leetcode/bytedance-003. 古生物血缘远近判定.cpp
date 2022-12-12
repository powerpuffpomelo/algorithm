#include <bits/stdc++.h>
using namespace std;

string str, str1, str2;

int main(){
    cin >> str;
    int p = 0;
    while(str[p] != ',') p++;
    str1 = str.substr(0, p);
    str2 = str.substr(p + 1);
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) dp[i][0] = i;
    for(int i = 1; i <= m; i++) dp[0][i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (str1[i - 1] == str2[j - 1] ? 0 : 1));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}