#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 1e5 + 10;
int n, a[N];
int stk[N], l[N], r[N];

int main(){
    while(cin >> n, n){
        for(int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n + 1] = -1;
        
        int tt = 0;
        stk[tt] = 0;
        for(int i = 1; i <= n; i++){
            while(a[i] <= a[stk[tt]]) tt--;
            l[i] = stk[tt];
            stk[++tt] = i;
        }
        
        tt = 0;
        stk[tt] = n + 1;
        for(int i = n; i >= 1; i--){
            while(a[i] <= a[stk[tt]]) tt--;
            r[i] = stk[tt];
            stk[++tt] = i;
        }
        
        lld ans = 0;
        for(int i = 1; i <= n; i++){
            int h = a[i];
            int w = r[i] - l[i] - 1;
            ans = max(ans, (lld)h * w);
        }
        cout << ans << endl;
    }
    return 0;
}