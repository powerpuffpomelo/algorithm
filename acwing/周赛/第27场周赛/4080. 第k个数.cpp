// 二分，第一个 小于等于自身的元素数量要大于等于k的元素

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
LL n, m, k;

bool check(LL x){
    LL res = 0;
    for(int i = 1; i <= n; i++){
        res += min(m, x / i);     // 数据类型要统一
    }
    return res >= k;
}

int main(){
    cin >> n >> m >> k;
    LL l = 1, r = n * m;
    while(l < r){
        LL mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}