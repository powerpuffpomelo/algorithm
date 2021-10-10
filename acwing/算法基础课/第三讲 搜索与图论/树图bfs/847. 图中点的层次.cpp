// ###################################################### 版本1 ###################################################### //

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

// ###################################################### 版本2 ###################################################### //

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int d[N];
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(){
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(t == n) return d[t];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] != -1) continue;
            q.push(j);
            d[j] = d[t] + 1;
        }
    }
    return -1;
}

int main(){
    memset(h, -1, sizeof(h));
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}