// 如果想不到公式，想不到闭式解递推直接计算答案的话，可以正着推，用二分找答案
// O(logn)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N];

bool check(int x){
    for(int i = 0; i < n; i++){
        x = x * 2 - h[i];
        if(x >= 1e5) return true;
        if(x < 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];
    int l = 0, r = 1e5;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}