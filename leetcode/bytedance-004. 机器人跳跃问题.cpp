// ###################################################### 版本1 ###################################################### //
// 二分
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N];

bool check(int e){
    for(int i = 1; i <= n; i++){
        e += e - h[i];
        if(e > N) return true;   // 务必剪枝！
        if(e < 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    int l = 0, r = N;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}