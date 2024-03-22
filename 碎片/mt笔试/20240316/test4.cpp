#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n;
int h[N];   // h[i]记录高度，每遇见一个1就+1，遇见一个2就-1
int tr[N * 2];  // tr[i]记录每种高度的出现次数
ll ans;

int lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x; i <= n * 2 + 2; i += lowbit(i)) tr[i] += c;
}

int sum(int x){
    ll ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += tr[i];
    return ret;
}

int main(){
    cin >> n;
    h[0] = n + 1;   // 初始偏移量，防止tr越界
    add(h[0], 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        h[i] = h[i - 1] + (x == 1 ? 1 : -1);
        ans += sum(h[i]) + 2 * (i - sum(h[i]));  // 前边有多少比h[i]低的数，这些区间众数为1，其余区间众数为2
        add(h[i], 1);
    }
    cout << ans << endl;
    return 0;
}