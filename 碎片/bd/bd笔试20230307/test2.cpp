#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
int a[N], dp[N][2];
long long white, black;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > 0) a[i] = 1;
        else a[i] = -1;
    }
    if(a[0] == 1) dp[0][0] = 1, white++;
    else dp[0][1] = 1, black++;
    for(int i = 1; i < n; i++){
        if(a[i] == -1){
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }else{
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
        }
        white += dp[i][0];
        black += dp[i][1];
    }
    cout << black << ' ' << white << endl;
    return 0;
}