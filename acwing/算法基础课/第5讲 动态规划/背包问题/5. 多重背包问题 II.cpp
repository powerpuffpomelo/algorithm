/*
多重背包的二进制优化，转换成01背包问题
从O(nms)到O(nmlogs)，其中n是物品种数，m是背包容量，s是每种物品的数量限制
相当于把每种物品的数量限制s 划分成 1 2 4 8 等等数量打包，使之能01组合出0到s中的任意数量
*/
// ###################################################### 版本2 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, m;
long long dp[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        for(int k = 1; k <= s; s -= k, k *= 2){
            for(int j = m; j >= k * v; j--){
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
        if(s){
            for(int j = m; j >= s * v; j--){
                dp[j] = max(dp[j], dp[j - s * v] + s * w);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 12000, V = 2010;
int n, m;
int v[N], w[N], idx, dp[V];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b, s;
        cin >> a >> b >> s;
        int j = 1;
        while(j <= s){
            v[idx] = j * a, w[idx] = j * b;
            s -= j;
            j *= 2;
            idx++;
        }
        if(s){
            v[idx] = s * a, w[idx] = s * b;
            idx++;
        }
    }
    for(int i = 0; i < idx; i++){
        for(int j = m; j >= v[i]; j--){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}