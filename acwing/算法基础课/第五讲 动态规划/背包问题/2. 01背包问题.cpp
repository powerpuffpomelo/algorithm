#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int w[N], v[N];    // w 重量（体积）；v 价值
int dp[N];         // dp[i][j]代表 前i件物品放入体积不超j的背包的最大价值，一维是二维的省略版
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
