// dfs+剪枝会tle，所以要考虑dp
// 卡特兰数
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 40;
int n;
lld c[N][N];

int main(){
    cin >> n;
    for(int i = 0; i <= 2 * n; i++){
        for(int j = 0; j <= i; j++){
            c[i][j] = j ? c[i - 1][j - 1] + c[i - 1][j] : 1;   // 求组合数
        }
    }
    cout << c[2 * n][n] / (n + 1) << endl;
    return 0;
}