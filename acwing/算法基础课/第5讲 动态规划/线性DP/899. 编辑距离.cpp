// ###################################################### 版本2 ###################################################### //
// 用vector和string
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> vec;
int dp[12][12];

int edit_distance(string a, string b){
    int x = a.size(), y = b.size();
    a = ' ' + a, b = ' ' + b;
    for(int i = 0; i <= x; i++) dp[i][0] = i;
    for(int j = 0; j <= y; j++) dp[0][j] = j;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return dp[x][y];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }
    while(m--){
        string str;
        int lim;
        cin >> str >> lim;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(edit_distance(str, vec[i]) <= lim) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
char a[N][12], b[12];
int n, m, limit;

int edit_distance(char x[], char y[]){
    int lenx = strlen(x + 1), leny = strlen(y + 1);    // 注意要计算x+1位置的strlen
    int dp[12][12] = {0};
    for(int i = 1; i <= lenx; i++) dp[i][0] = i;
    for(int j = 1; j <= leny; j++) dp[0][j] = j;
    for(int i = 1; i <= lenx; i++){
        for(int j = 1; j <= leny; j++){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (x[i] != y[j]));  // 简洁写法
        }
    }
    return dp[lenx][leny];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i] + 1;
    while(m--){
        cin >> b + 1 >> limit;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(edit_distance(a[i], b) <= limit) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}