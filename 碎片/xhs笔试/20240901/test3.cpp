#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5010;
int n, m;
LL all_ans;
LL a[N], sum[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        all_ans += sum[i - 1];
    }
    for(int j = 0; j < m; j++){
        LL u = -1, mmax = 0;  // 最大可以减多少
        for(int i = 1; i <= n - j; i++){  // 目前数组的长度
            LL x = sum[i - 1] + a[i] * (n - j - i);
            if(x > mmax){
                u = i, mmax = x;
            }
        }
        all_ans -= mmax;
        LL cp = a[u];
        for(int i = u; i <= n - j - 1; i++){
            a[i] = a[i + 1];
            sum[i] = sum[i + 1] - cp;
        }
    }
    cout << all_ans << endl;
    return 0;
}