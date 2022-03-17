// ###################################################### 版本3 ###################################################### //
// vector邻接表易于理解
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
vector<int> adj[N];
vector<int> ans;
int ind[N];

void add(int x, int y){
    adj[x].push_back(y);
    ind[y]++;
}

bool top_sort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!ind[i]) q.push(i);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for(int i = 0; i < adj[t].size(); i++){
            int u = adj[t][i];
            if(--ind[u] == 0) q.push(u);
        }
    }
    if(ans.size() == n) return true;
    else return false;
}

int main(){
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    if(top_sort()){
        for(auto x : ans) cout << x << ' ';
    }else{
        cout << -1 << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int d[N];  // 记录入度
vector<int> ans;  // 记录最终保存拓扑序列
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    d[b]++;
}

void topsort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(d[i] == 0) q.push(i);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0) q.push(j);
        }
    }
    if(ans.size() == n){
        for(int i = 0; i < n; i ++) printf("%d ", ans[i]);
        puts("");
    }else{
        printf("-1\n");
    }
}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    topsort();
    return 0;
}

// ###################################################### 版本2 ###################################################### //

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int q[N], d[N];   // 数组模拟队列，可以不新开记录结果的队列，直接保存答案
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    d[b]++;
}

bool topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i ++){
        if(d[i] == 0) q[++tt] = i;
    }
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0) q[++tt] = j;
        }
    }
    return tt == n - 1;  // 如果所有的点都曾入度为0被放进队列，则是有向无环图
}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    if(topsort()){
        for(int i = 0; i < n; i++) printf("%d ", q[i]);
        puts("");
    }else{
        printf("-1\n");
    }
    return 0;
}