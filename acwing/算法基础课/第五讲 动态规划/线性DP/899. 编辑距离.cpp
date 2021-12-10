#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
char a[N][12], b[12];
int n, m, limit;

int edit_distance(char x[], char y[]){
    int lenx = strlen(x + 1), leny = strlen(y + 1);    // 注意要计算x+1的strlen
    int dp[12][12] = {0};
    for(int i = 1; i <= lenx; i++) dp[i][0] = i;
    for(int j = 1; j <= leny; j++) dp[0][j] = j;
    for(int i = 1; i <= lenx; i++){
        for(int j = 1; j <= leny; j++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (x[i] != y[j]));  // 简洁写法
        }
    }
    return dp[lenx][leny];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i] + 1;
    while(m--){
        cin >> b + 1 >> limit;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(edit_distance(a[i], b) <= limit) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}