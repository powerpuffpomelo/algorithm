#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 10;
int n;
int a[N];   // 原数组
ll tr[N];   // 记录目前每个元素的出现次数
ll ans;   // 原数组 逆序对的数量

int lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x){
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += tr[i];
    return ret;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        add(a[i], 1);
        ans += sum(n) - sum(a[i]);
    }
    memset(tr, 0, sizeof tr);
    for(int i = 1; i <= n; i++){
        add(a[i], 1);
        // 增加的逆序对数量：前边有多少个比a[i]小的数 = sum(a[i] - 1)
        // 减少的逆序对数量：后面有多少个比a[i]小的数 = (a[i] - 1) - sum(a[i] - 1)
        cout << ans + sum(a[i] - 1) * 2 - a[i] + 1 << ' ';
    }
    return 0;
}