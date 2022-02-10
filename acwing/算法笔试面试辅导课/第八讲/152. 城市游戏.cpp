// ###################################################### 版本2 ###################################################### //
// 优化一点
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, g[N][N], stk[N], tt, l[N], r[N], ans;

int cal(int h[]){  // 单独把 直方图中最大矩形 包装成函数
    h[0] = h[m + 1] = -1;
    
    tt = 0;
    stk[tt] = 0;
    for(int j = 1; j <= m; j++){
        while(h[j] <= h[stk[tt]]) tt--;
        l[j] = stk[tt];
        stk[++tt] = j;
    }
    
    tt = 0;
    stk[tt] = m + 1;
    for(int j = m; j >= 1; j--){
        while(h[j] <= h[stk[tt]]) tt--;
        r[j] = stk[tt];
        stk[++tt] = j;
    }
    
    int ret = 0;
    for(int j = 1; j <= m; j++){
        int hh = h[j], ww = r[j] - l[j] - 1;
        ret = max(ret, hh * ww);
    }
    return ret;
}

int main(){
    cin >> n >> m;
    char c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c;
            if(c == 'F') g[i][j] = g[i - 1][j] + 1;  // 只存h数组就可以
        }
    }
    for(int i = 1; i <= n; i++) ans = max(ans, cal(g[i]));
    cout << ans * 3 << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, g[N][N], h[N], stk[N], tt, l[N], r[N], ans;

int main(){
    cin >> n >> m;
    char c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c;
            if(c == 'F') g[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j]) h[j] += 1;
            else h[j] = 0;
        }
        h[0] = h[m + 1] = -1;
        tt = 0;
        stk[tt] = 0;
        for(int j = 1; j <= m; j++){
            while(h[j] <= h[stk[tt]]) tt--;
            l[j] = stk[tt];
            stk[++tt] = j;
        }
        tt = 0;
        stk[tt] = m + 1;
        for(int j = m; j >= 1; j--){
            while(h[j] <= h[stk[tt]]) tt--;
            r[j] = stk[tt];
            stk[++tt] = j;
        }
        int tmp = 0;
        for(int j = 1; j <= m; j++){
            int hh = h[j], ww = r[j] - l[j] - 1;
            tmp = max(tmp, hh * ww);
        }
        ans = max(ans, tmp);
    }
    cout << ans * 3 << endl;
    return 0;
}