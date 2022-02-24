/*
多重背包的二进制优化，转换成01背包问题
从O(nms)到O(nmlogs)，其中n是物品种数，m是背包容量，s是每种物品的数量限制
相当于把每种物品的数量限制s 划分成 1 2 4 8 等等数量打包，使之能01组合出0到s中的任意数量
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20000, M = 2010;
int w[N], v[N];
int dp[M];
int n, m, idx = 1;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int a, b, s;
        cin >> a >> b >> s;
        int j = 1;
        while(j <= s){
            w[idx] = j * a;
            v[idx] = j * b;
            s -= j;
            j *= 2;
            idx++;
        }
        if(s){
            w[idx] = s * a;
            v[idx] = s * b;
            idx++;
        }
    }
    for(int i = 1; i < idx; i++){
        for(int j = m; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}