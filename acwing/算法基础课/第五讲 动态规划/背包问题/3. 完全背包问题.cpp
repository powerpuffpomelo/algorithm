// ###################################################### 版本1 ###################################################### //
// 节约空间，滚动数组

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int w[N], v[N];
int dp[N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = w[i]; j <= m; j++){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 朴素做法 过渡

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int w[N], v[N];
int dp[N][N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
// 朴素做法

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int w[N], v[N];
int dp[N][N];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k * w[i] <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}