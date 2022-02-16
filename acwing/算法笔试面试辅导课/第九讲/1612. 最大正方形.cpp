// ###################################################### 版本2 ###################################################### //
// dp
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
int dp[N][N];
int edge_max;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            if(x){
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                edge_max = max(edge_max, dp[i][j]);
            }
        }
    }
    cout << edge_max * edge_max << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版，单调栈
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int h[N];
int n, m;
int ans;

void cal(int h[]){
    h[0] = h[m + 1] = -1;
    int l[N], r[N];
    stack<int> stk;
    stk.push(0);
    l[1] = 0;
    for(int i = 2; i <= m; i++){
        while(h[i] <= h[stk.top()]) stk.pop();
        l[i] = stk.top();
        stk.push(i);
    }
    stk = stack<int>();
    stk.push(m + 1);
    r[m] = m + 1;
    for(int i = m - 1; i >= 1; i--){
        while(h[i] <= h[stk.top()]) stk.pop();
        r[i] = stk.top();
        stk.push(i);
    }
    for(int i = 1; i <= m; i++){
        int height = h[i], width = r[i] - l[i] - 1;
        int ll = min(height, width);
        ans = max(ans, ll * ll);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            h[j] = x ? h[j] + 1 : 0;
        }
        cal(h);
    }
    cout << ans << endl;
    return 0;
}
