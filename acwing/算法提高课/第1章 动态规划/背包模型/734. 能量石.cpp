// ###################################################### 版本1 ###################################################### //
// 贪心（邻项交换）+ 01背包
// 计算第i个物品和第i-1个物品 交换顺序与否 能得到的能量总和，
// 发现只要 si * l(i+1) < s(i + 1) * li 的话，i放在i+1前就能获取更多的能量总和。
// 我们假设 吃到的时候能量已经为0的能量石 就不吃了，那么相当于从所有能量石中选择一部分能量石吃掉，就是01背包
// 而选择好这一部分要吃的能量石后，还有顺序问题，就按照最优方法贪心排序。等价于先贪心排序再01背包
#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 1e5 + 10;
int n, m, T;
struct Stone{
    int s, e, l;
    bool operator < (const Stone &W) const{
        return s * W.l < l * W.s;
    }
}stones[N];
int dp[M];  // 前i个石头，总时间恰好为j，的最大能量

int main(){
    cin >> T;
    for(int c = 1; c <= T; c++){
        cin >> n;
        int m = 0;
        for(int i = 0; i < n; i++){
            cin >> stones[i].s >> stones[i].e >> stones[i].l;
            m += stones[i].s;
        }
        sort(stones, stones + n);
        memset(dp, -0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            int s = stones[i].s, e = stones[i].e, l = stones[i].l;
            for(int j = m; j >= s; j--){
                dp[j] = max(dp[j], dp[j - s] + e - (j - s) * l);
            }
        }
        int ans = 0;
        for(int j = 0; j <= m; j++) ans = max(ans, dp[j]);
        printf("Case #%d: %d\n", c, ans);
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

int n;
struct Stone
{
    int s, e, l;
}stones[N];

bool cmp(Stone a, Stone b)
{
    return a.s * b.l < b.s * a.l;
}

int f[N][M];

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n;
        int m = 0;
        for (int i = 1; i <= n; i ++ )
        {
            int s, e, l;
            cin >> s >> e >> l;
            stones[i] = {s, e, l};
            m += s;
        }

        sort(stones + 1, stones + 1 + n, cmp);

        for (int i = 1; i <= n; i ++ )
            for (int j = 0; j <= m; j ++ )
            {
                f[i][j] = f[i - 1][j];
                if (j >= stones[i].s)
                {
                    int s = stones[i].s, e = stones[i].e, l = stones[i].l;
                    f[i][j] = max(f[i][j], f[i - 1][j - s] + max(0, e - l * (j - s)));
                }
            }

        int res = 0;
        for (int i = 0; i <= m; i ++ ) res = max(res, f[n][i]);

        printf("Case #%d: %d\n", C, res);
    }

    return 0;
}
