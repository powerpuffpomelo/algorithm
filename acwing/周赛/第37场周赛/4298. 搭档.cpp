// ###################################################### 版本2 ###################################################### //
// 贪心
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, a[N], b[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(j < m && b[j] < a[i] - 1) j++;
        if(j < m && b[j] <= a[i] + 1){
            ans++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 匈牙利算法
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, a[N], b[N];
int st[N], match[N];
int ans;

bool find(int x){
    for(int i = 1; i <= m; i++){
        if(b[i] - a[x] <= 1 && b[i] - a[x] >= -1){
            if(!st[i]){
                st[i] = 1;
                if(!match[i] || find(match[i])){
                    match[i] = x;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 1; i <= n; i++){
        fill(st, st + N, 0);
        if(find(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
