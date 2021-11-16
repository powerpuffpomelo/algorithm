// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int color[N];
int n, m;

void add(int u, int v){
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

bool dfs(int u, int c){
    color[u] = c;
    for(int j = h[u]; j != -1; j = ne[j]){
        int v = e[j];
        if(!color[v]){
            if(!dfs(v, 3 - c)) return false;
        }
        else if(color[v] == c) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}

// ###################################################### 版本2 ###################################################### //

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10, M = N * 2;      // 无向图，边是二倍，M要设为2*N
int h[N], e[M], ne[M], idx;
int n, m;
int belong[N], inq[N];


void add(int u, int v){
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

bool ran(int u){
    belong[u] = 0;
    queue<int> q;
    q.push(u);
    inq[u] = 1;
    while(q.size()){
        int t = q.front();
        q.pop();
        int bt = belong[t];
        for(int j = h[t]; j != -1; j = ne[j]){
            int v = e[j];
            if(belong[v] == bt) return false;
            belong[v] = (bt + 1) % 2;
            if(!inq[v]){
                q.push(v);
                inq[v] = 1;
            }
        }
    }
    return true;
}

bool check(){
    for(int i = 1; i <= n; i++){
        if(belong[i] == -1){
            if(!ran(i)) return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    memset(belong, -1, sizeof(belong));
    while(m--){
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    if(check()) puts("Yes");
    else puts("No");
    return 0;
}