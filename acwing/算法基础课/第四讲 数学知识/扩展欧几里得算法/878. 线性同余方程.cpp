// 转换成扩展欧几里得，a * x = b (mod m) -> a * x + m * y = b，有解前提是 (a, m) | b
#include <iostream>
using namespace std;

typedef long long lld;
int n, a, b, m, x, y;

int exgcd(int a, int b, int& x, int& y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b >> m;
        int d = exgcd(a, m, x, y);
        if(b % d) puts("impossible");
        else cout<< (lld)b / d * x % m << endl;
    }
    return 0;
}