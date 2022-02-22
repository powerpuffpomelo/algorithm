// 最大值最小值 想到二分
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n, k, a[N], st[N], ed[N];

bool check(int sum){
    int s = 0, cnt = 1;
    ed[1] = n;
    for(int i = n; i; i--){
        if(s + a[i] <= sum) s += a[i];
        else{
            st[cnt] = i + 1;
            ed[++cnt] = i;
            s = a[i];
        }
    }
    st[cnt] = 1;
    return cnt <= k;
}

int main(){
    cin >> n >> k;
    int l = 0, r = 1e9;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        l = max(l, a[i]);
    } 
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    check(l);
    for(int i = k; i; i--){
        cout << st[i] << ' ' << ed[i] << endl;
    }
    return 0;
}