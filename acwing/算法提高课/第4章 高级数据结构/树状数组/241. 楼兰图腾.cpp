#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n, a[N], tr[N];     // tr[i]的单个元素 维护i这个数在数组中的出现次数
int Greater[N], lower[N];  // Greater[i]代表第i个位置左侧 值更大的数的数量

int lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

ll sum(int x){
    ll ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += tr[i];
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        int y = a[i];
        Greater[i] = sum(n) - sum(y);
        lower[i] = sum(y - 1);
        add(y, 1);
    }
    memset(tr, 0, sizeof tr);
    ll ans1 = 0, ans2 = 0;
    for(int i = n; i >= 1; i--){
        int y = a[i];
        ans1 += Greater[i] * (ll)(sum(n) - sum(y));
        ans2 += lower[i] * (ll)sum(y - 1);
        add(y, 1);
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}