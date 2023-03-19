// 55%
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> vec1, vec2;
vector<vector<int>> dp;
int ans = 1e9;
vector<int> temp;

int main(){
    cin >> n;
    temp = vector<int>(n + 1);
    dp = vector<vector<int>>(2, vector<int>(n + 1));
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec1.push_back(x);
        vec2.push_back(x);
    }
    reverse(vec2.begin(), vec2.end());
    for(int i = 1, t = 1; i <= n; i++, t = 1 - t){
        for(int j = 1; j <= (n - i); j++){
            dp[t][j] = max(dp[1 - t][j], dp[t][j - 1]);
            if(vec1[i - 1] == vec2[j - 1]) dp[t][j] = max(dp[t][j], dp[1 - t][j - 1] + 1);
        }
        temp[i] = dp[t][n - i];
    }
    for(int i = 0; i <= n; i++){
        ans = min(ans, n - 2 * temp[i]);
    }
    cout << ans - 1 << endl;
    return 0;
}