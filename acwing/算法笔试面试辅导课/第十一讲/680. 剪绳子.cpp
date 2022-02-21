// 浮点二分
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, a[N];

bool check(double x){
    int num = 0;
    for(int i = 0; i < n; i++){
        num += a[i] / x;
        if(num >= m) return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    double l = 0, r = 1e9;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        r = min(r, (double)a[i]);
    }
    
    while(r - l > 1e-4){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n", l);
    return 0;
}