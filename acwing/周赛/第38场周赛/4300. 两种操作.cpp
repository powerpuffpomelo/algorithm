// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
typedef pair<int, int> pii;
int n, m;
int vis[N];

int bfs(){
    queue<pii> q;
    q.push({m, 0});
    vis[m] = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t.first, c = t.second;
        int ha = x / 2, hb = x + 1;
        if((x % 2 == 0 && ha == n)|| hb == n) return c + 1;
        if(x % 2 == 0 && !vis[ha]){
            vis[ha] = 1;
            q.push({ha, c + 1});
        }
        if(!vis[hb]){
            vis[hb] = 1;
            q.push({hb, c + 1});
        }
    }
}

int main(){
    cin >> n >> m;
    cout << bfs() << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 我的初版-优化
#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
typedef pair<int, int> pii;
int n, m;
int vis[N];

int bfs(){
    queue<pii> q;
    q.push({n, 0});
    vis[n] = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t.first, c = t.second;
        int ha = x * 2, hb = x - 1;
        if(ha == m|| hb == m) return c + 1;
        if(ha < N && !vis[ha]){
            vis[ha] = 1;
            q.push({ha, c + 1});
        }
        if(hb >= 1 && !vis[hb]){
            vis[hb] = 1;
            q.push({hb, c + 1});
        }
    }
}

int main(){
    cin >> n >> m;
    cout << bfs() << endl;
    return 0;
}