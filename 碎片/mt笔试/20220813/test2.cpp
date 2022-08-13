#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, k;
string str;
int vis[N][N];
int area;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
map<char, int> ma;
int cnt;

int main(){
    cin >> n >> m >> k >> str;
    area = n * m;
    ma['W'] = 0, ma['A'] = 1, ma['S'] = 2, ma['D'] = 3;
    int x = 0, y = 0;
    vis[0][0] = 1, cnt = 1;
    for(int i = 0; i < k; i++){
        int d = ma[str[i]];
        x += dx[d], y += dy[d];
        if(!vis[x][y]){
            vis[x][y] = 1;
            cnt++;
        }
        if(cnt == area){
            cout << "Yes" << endl;
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "No" << endl << area - cnt << endl;
    return 0;
}