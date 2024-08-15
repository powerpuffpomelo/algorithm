#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n; 
int a[N];
ll ans;

void dfs(int ed, int remain, ll sum, ll& ret, vector<int>& vis){
    if(remain == 0){
        ret = max(ret, sum);
        return;
    }
    for(int i = 1; i <= 4; i++){
        if(!vis[i - 1] && i <= remain && sum + a[ed - remain + i] >= 0){
            vis[i - 1] = 1;
            dfs(ed, remain - i, sum + a[ed - remain + i], ret, vis);
            vis[i - 1] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    bool flag = true;
    for(int i = 10; i <= n; i += 10){
        vector<int> vis(4);  // 是否用过 1234
        ll ret = -1;
        dfs(i, 10, 0, ret, vis);
        if(ret == -1){
            flag = false;
            break;
        }
        ans += ret;
    }
    if(flag){
        vector<int> vis(4);  // 是否用过 1234
        ll ret = -1;
        dfs(n, n % 10, 0, ret, vis);
        ans += ret;
    }
    if(!flag){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}