#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int n, m;
double p[N], a[N];
double ans;

int main(){
    cin >> n >> m;
    vector<double> gain(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i] / 100 * p[i];
        gain[i] = a[i] / 100 * (100 - p[i]);
    }
    sort(gain.begin(), gain.end());
    int i = n - 1;
    while(m--) ans += gain[i--];
    printf("%.2f\n", ans);
    return 0;
}