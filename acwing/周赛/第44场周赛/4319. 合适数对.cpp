// ###################################################### 版本1 ###################################################### //
// 绝绝子！
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 1e5 + 10;
int n, k, a;
unordered_map<lld, int> cnt;    // 在计算互补的lld z的时候，如果用int键映射，可能导致更小的数cnt++，所以这里键必须lld
lld ans;  // 注意答案范围可能爆int

lld power(int a, int b){
    lld ret = 1;
    while(b--){
        ret *= a;
        if(ret  > N) return 0;   // 需要自己写pow函数，防止越界
    }
    return ret;
}

void divide(int x){
    lld y = 1, z = 1;    // y和z分别代表，自身计数的键、互补的键，z可能很大所以lld
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            int s = 0;
            while(x % i == 0){
                s++;
                x /= i;
            }
            s %= k;   // 只需记录%k的指数
            if(s){
                y *= power(i, s);   // 由于数值范围不超N，所以直接把这个数本身当成键就可以！
                z *= power(i, k - s);
            }
            
        }
    }
    if(x > 1){
        y *= x;
        z *= power(x, k - 1);
    }
    if(z > N) z = 0;  // 所有数都是N范围内的，找不到超出N的，所以不用管
    ans += cnt[z];
    cnt[y]++;
}

int main(){
    cin >> n >> k;
    while(n--){
        cin >> a;
        divide(a);
    }
    cout << ans << endl;
    return 0;
}