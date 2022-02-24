#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 1e6 + 10;
int n;
lld s[N], c[N];
lld avg, ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    avg = s[n] / n;
    for(int i = 2; i <= n; i++){
        c[i] = (i - 1) * avg - (s[n] - s[n - i + 1]);
    }
    sort(c + 1, c + n + 1);
    for(int i = 1, j = n; i < j; i++, j--){
        ans += c[j] - c[i];
    }
    cout << ans << endl;
    return 0;
}