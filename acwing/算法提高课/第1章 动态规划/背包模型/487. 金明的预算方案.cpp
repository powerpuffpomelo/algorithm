// ###################################################### 版本1 ###################################################### //
// 分组背包。可以将每个主件及其附件看作一个物品组。
// 记主件为p，两个附件为a b，则共4种组合：p，pa，pb，pab。这四种组合互斥
// 时间复杂度O(nm)
#include <bits/stdc++.h>
using namespace std;

#define v first
#define w second

const int N = 61, M = 32010;
int n, m;
int dp[M];
typedef pair<int, int> pii;
pii master[N];
vector<pii> servant[N];

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        int v, p, q;
        cin >> v >> p >> q;
        if(!q) master[i] = {v, p * v};
        else servant[q].push_back({v, p * v});
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 0; j--){
            for(int k = 0; k < 1 << servant[i].size(); k++){ // 二进制遍历每种情况（该分组下的每种物品）
                int v = master[i].v, w = master[i].w;
                for(int u = 0; u < servant[i].size(); u++){ // 遍历每一个附件
                    if(k >> u & 1){ // 如果该情况选择了该附件
                        v += servant[i][u].v, w += servant[i][u].w;
                    }
                }
                if(j >= v) dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}