#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long a[N];
int n;

int main(){
    cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i) ans += max(0ll, a[i - 1] - a[i] + 1);
    }
    cout << ans << endl;
    return 0;
}