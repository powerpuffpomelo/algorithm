// ###################################################### 版本2 ###################################################### //
// 可以优化一点的！
#include <bits/stdc++.h>
using namespace std;

const int N = 2048;
int n, e[N];
int ans;

int cal_depth(int root){
    if(root >= 1<<n) return 0;
    int l_depth = cal_depth(root * 2) + e[root * 2];
    int r_depth = cal_depth(root * 2 + 1) + e[root * 2 + 1];
    ans += abs(l_depth - r_depth);
    return max(l_depth, r_depth);
}

int main(){
    cin >> n;
    for(int i = 2; i < 1<<(n + 1); i++) cin >> e[i];
    cal_depth(1);
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 2048;
int n, e[N], d[N];
int ans;

int cal_depth(int root){
    if(root >= 1<<n) return 0;
    if(d[root]) return d[root];
    int l_depth = cal_depth(root * 2) + e[root * 2];
    int r_depth = cal_depth(root * 2 + 1) + e[root * 2 + 1];
    d[root] = max(l_depth, r_depth);
    return d[root];
}

int main(){
    cin >> n;
    for(int i = 2; i < 1<<(n + 1); i++) cin >> e[i];
    cal_depth(1);
    for(int i = 2; i < 1<<(n + 1); i++){
        int p = i / 2;
        ans += d[p] - d[i] - e[i];
    }
    cout << ans << endl;
    return 0;
}