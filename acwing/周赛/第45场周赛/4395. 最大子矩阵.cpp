#include <bits/stdc++.h>
using namespace std;

const int N = 2010, INF = 1e8;
int n, m, X;
int s1[N], s2[N];
int a[N], b[N];  // a[i]表示，a数组中长度为i的子序列和的最小值

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s1[i] = s1[i - 1] + x;
    }
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        s2[i] = s2[i - 1] + x;
    }
    for(int len = 1; len <= n; len++){
        a[len] = INF;
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            a[len] = min(a[len], s1[j] - s1[i - 1]);
        }
    }
    for(int len = 1; len <= m; len++){
        b[len] = INF;
        for(int i = 1; i + len - 1 <= m; i++){
            int j = i + len - 1;
            b[len] = min(b[len], s2[j] - s2[i - 1]);
        }
    }
    cin >> X;
    int ans = 0;
    for(int i = 1, j = m; i <= n; i++){  // 对每个i，都找一个尽可能大的j
        while(j && a[i] > X / b[j]) j--;
        ans = max(ans, i * j);
    }
    cout << ans << endl;
    return 0;
}