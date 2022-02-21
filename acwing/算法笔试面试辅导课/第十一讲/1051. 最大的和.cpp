#include <bits/stdc++.h>
using namespace std;

const int N = 50010, INF = 1e9;
int T, n, a[N], lmax[N], rmax[N];

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int s;
        lmax[0] = -INF;
        for(int i = 1, s = 0; i <= n; i++){
            s = max(s, 0) + a[i];  // 无需存储
            lmax[i] = max(lmax[i - 1], s);
        }
        rmax[n + 1] = -INF;
        for(int i = n, s = 0; i > 0; i--){
            s = max(s, 0) + a[i];
            rmax[i] = max(rmax[i + 1], s);
        }
        
        int ans = -INF;
        for(int i = 1; i < n; i++){
            ans = max(ans, lmax[i] + rmax[i + 1]);
            
        }
        cout << ans << endl;
    }
    return 0;
}