// ###################################################### 版本1 ###################################################### //
// 时间复杂度O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n, ans = 0;

int main(){
    cin >> n;
    if(n % 2){          // 分奇偶数情况讨论，类似于脑筋急转弯
        for(int i = 3; i <= n / i; i++){
            if(n % i == 0){
                n -= i;
                ans++;
                break;
            }
        }
        if(n % 2){
            ans++;
            n = 0;
        }
    }
    ans += n / 2;
    cout << ans << endl;
    return 0;
}