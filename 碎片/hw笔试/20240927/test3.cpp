#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 110;
int m, n, a1, a2, b1, b2;
int st[N][N], ans[N][N], vis[N][N], temp[N][N], ganran[N][N];
int num[N][N]; // 危险系数最大值
queue<pii> patient;
int dang;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void bfs(int x, int y, int dang){
    queue<pii> q;
    q.push({x, y});
    temp[x][y] = dang;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        dang = temp[x][y];
        num[x][y] = max(num[x][y], dang);
        vis[x][y] = 1;
        for(int d = 0; d < 4; d++){
            int a = x + dx[d], b = y + dy[d];
            if(a < 1 || a > m || b < 1 || b > n || vis[a][b] || st[a][b] == 1) continue;
            q.push({a, b});
            temp[a][b] = dang - 1;
        }
    }
}

int main(){
    cin >> m >> n >> a1 >> a2 >> b1 >> b2;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> st[i][j];  // 初始状态
            if(st[i][j] <= 1) ans[i][j] = -1;  // 该位置没有人
            else if(st[i][j] <= 3){
                ans[i][j] = 0;  // 初始就被感染
                patient.push({i, j});
            }
            else ans[i][j] = -1;  // 先假设没被感染，感染了再改。
        }
    }
    int day = 1;
    while(patient.size()){  // 当存在新增传播源的时候
        while(patient.size()){   // 今天这波病人
            auto t = patient.front();
            patient.pop();
            int x = t.first, y = t.second;
            if(st[x][y] == 2 || st[x][y] == 4) dang = a2;  // 不戴口罩
            else if(st[x][y] == 3 || st[x][y] == 5) dang = a1;  // 戴口罩
            fill(vis[0], vis[0] + N * N, 0);
            bfs(x, y, dang);
        }
        for(int a = 1; a <= m; a++){
            for(int b = 1; b <= n; b++){
                if(ganran[a][b]) continue;
                if((st[a][b] == 4 && num[a][b] >= b2) || (st[a][b] == 5 && num[a][b] >= b1)){
                    patient.push({a, b});  // 明天的病人
                    ans[a][b] = day;
                    ganran[a][b] = 1;
                }
            }
        }
        day += 1;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}