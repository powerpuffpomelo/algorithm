#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 3e4 + 10;
int n, m;
LL t;
LL a[N], b[N], sa[N], sb[N];

int main(){
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sa[i] = sa[i - 1] + a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        sb[i] = sb[i - 1] + b[i];
    }
    int ans = 0;
    for(int i = 0, j = m; i <= n; i++){
        if(sa[i] > t) break;
        while(j > 0 && sa[i] + sb[j] > t) j--;
        ans = max(ans, i + j);
    }
    cout << ans << endl;
    return 0;
}