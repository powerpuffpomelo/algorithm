#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int vis[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int start){
    queue<PII> q;
    q.push({start, 0});
    vis[start] = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int id = t.first, dis = t.second;
        if(id == n) return dis;
        for(int i = h[id]; i != -1; i = ne[i]){
            int j = e[i];
            if(vis[j]) continue;
            vis[j] = 1;
            q.push({j, dis + 1});
        }
    }
    return -1;
}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs(1) << endl;
    return 0;
}