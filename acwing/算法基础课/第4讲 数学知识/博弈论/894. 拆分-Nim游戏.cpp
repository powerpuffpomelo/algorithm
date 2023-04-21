#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int dp[N];

int sg(int x){
    if(dp[x] != -1) return dp[x];
    unordered_set<int> se;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            se.insert(sg(i) ^ sg(j));
        }
    }
    for(int i = 0; ; i++){
        if(!se.count(i)) return dp[x] = i;
    }
}

int main(){
    cin >> n;
    memset(dp, -1, sizeof dp);
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