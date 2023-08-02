#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int q[N];
int ans = N;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> q[i];
    for(int i = 1, j = 1, sum = 0; j <= n; j++){
        sum += q[j];
        while(sum - q[i] >= k) sum -= q[i++];
        if(sum >= k) ans = min(ans, j - i + 1);
    }
    cout << ans << endl;
    return 0;
}