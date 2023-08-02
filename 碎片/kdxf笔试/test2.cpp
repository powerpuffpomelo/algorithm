// 100%
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n;
int m[N];
long long ans;
long long factorial[N];
bool flag = false;

void dfs(int i, int cnt, int sum){
    if(sum == 60){
        ans += factorial[cnt] * factorial[n - cnt];
        flag = true;
        return;
    }
    if(i > n || sum > 60) return;
    // 不选
    dfs(i + 1, cnt, sum);
    // 选
    dfs(i + 1, cnt + 1, sum + m[i]);
}

int main(){
    factorial[0] = 1;
    for(int i = 1; i < N; i++) factorial[i] = factorial[i - 1] * i;
    cin >> n;
    int temp = 0;
    for(int i = 1; i <= n; i++) cin >> m[i], temp += m[i];
    if(temp != 180){
        cout << 0 << endl;
    }else{
        dfs(1, 0, 0);
        if(!flag) ans = 0;
        cout << ans << endl;
    }
    return 0;
}