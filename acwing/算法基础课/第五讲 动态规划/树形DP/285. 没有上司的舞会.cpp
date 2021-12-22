#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 6010;
int happy[N];
int h[N], e[N], ne[N], idx;
int dp[N][2];
int n;
bool has_parent[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int v){
    dp[v][1] = happy[v];
    for(int i = h[v]; ~i; i = ne[i]){    // -1补码是全1
        int j = e[i];
        dfs(j);
        dp[v][0] += max(dp[j][0], dp[j][1]);
        dp[v][1] += dp[j][0];
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> happy[i];
    }
    memset(h, -1, sizeof(h));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(b, a);
        has_parent[a] = true;
    }
    int root = 1;
    while(has_parent[root]) root++;
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}