/*
如果已经放好了横着的方块，那么竖着的只要塞进去就好，别无二选；
所以本题 总方案数=只放横着的小方块的合法方案数
如何判断方案合法？——看所有剩余位置，能否填满竖着的小方块。可以按列来看，每一列内部所有连续的空的小方块必须是偶数个
时间复杂度最坏 11 * 2^11 * 2^11
*/

// ###################################################### 版本1 ###################################################### //
// 朴素做法
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 12, M = 1 << N;
long long dp[N][M];   // dp[i][j]代表 已将前i-1列摆好 且第i-1列伸到第i列的小方块状态为j的方案数
bool st[M];   // 一个状态是否合法，如果有连续奇数空白则不合法
int n, m;

int main(){
    while(cin >> n >> m, n || m){
        for(int i = 0; i < 1 << n; i++){
            int cnt = 0;
            st[i] = true;
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }else{
                    cnt++;
                }
            }
            if(cnt & 1) st[i] = false;
        }
        memset(dp, 0, sizeof dp);   // long long 类型，似乎必须手动初始化
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < 1 << n; j++){
                for(int k = 0; k < 1 << n; k++){ // 看是否能从dp[i - 1][k] 转移到dp[i][j]
                    // (j & k) == 0 是因为不能在同一行有1，不然放不下横着的方块
                    // st[j | k] 是为了保证第i-1列空着的小方块能被竖着的小方块塞满，即连续空着的位置必须是偶数
                    if((j & k) == 0 && st[j | k]){  
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 去除无效状态的优化写法
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 12, M = 1 << N;
int n, m;
LL dp[N][M];
bool st[M];
vector<int> state[M];

int main(){
    while(cin >> n >> m, n || m){
        for(int i = 0; i < 1 << n; i++){
            st[i] = true;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    if(cnt % 2){
                        st[i] = false;
                        break;
                    }
                    cnt = 0;
                }else{
                    cnt++;
                }
            }
            if(cnt % 2) st[i] = false;
        }
        for(int i = 0; i < 1 << n; i++){
            state[i].clear();
            for(int j = 0; j < 1 << n; j++){
                if((i & j) == 0 && st[i | j]) state[i].push_back(j);
            }
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < 1 << n; j++){
                for(auto k : state[j]){
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}