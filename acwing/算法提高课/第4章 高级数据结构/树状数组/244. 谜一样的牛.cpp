// ###################################################### 版本1 ###################################################### //
// 树状数组 + 二分
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N], tr[N], ans[N];

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
    for(int i = 2; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) tr[i] = lowbit(i);  // 等价于 add(i, 1)。每个位置都是1，则区间和等于区间长度，tr[i]的区间长度是lowbit(i)
    for(int i = n; i >= 1; i--){
        int l = 1, r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(sum(mid) > h[i]) r = mid;
            else l = mid + 1;
        }
        ans[i] = l;
        add(l, -1);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}