#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, a, b;
int g[N][N], s[N][N];
int temp, ans;

int main(){
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + g[i][j];
        }
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            int x = max(0, i - a - 1), y = max(0, j - b - 1);
            temp = s[i][j] - s[i][y] - s[x][j] + s[x][y];
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}