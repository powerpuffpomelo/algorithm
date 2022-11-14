#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
typedef long long LL;
int q, a, b, c;

double cal(int a, int b, int c){
    double l = 0, r = 1000;
    while(r - l > eps){
        double mid = (l + r) / 2;
        double res = pow(mid, 3) + a * pow(mid, 2) + b * mid;
        if(res < c) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    cin >> q;
    while(q--){
        cin >> a >> b >> c;
        double x = cal(a, b, c);
        printf("%.8f\n", x);
    }
    return 0;
}