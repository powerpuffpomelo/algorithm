/*
记忆化搜索
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 10010;
int n, k;
int s[N], dp[M];  // dp 记忆化搜索

int sg(int x){
    if(dp[x] != -1) return dp[x];
    unordered_set<int> se;
    for(int i = 0; i < k; i++){
        if(x >= s[i]) se.insert(sg(x - s[i]));
    }
    for(int i = 0; ; i++){
        if(!se.count(i)) return dp[x] = i;
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++) cin >> s[i];
    memset(dp, -1, sizeof dp);
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans ^= sg(x);
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}