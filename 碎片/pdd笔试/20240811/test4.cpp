// 有问题，还需要改
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
vector<int> adj[N];
vector<int> ans;
int ind[N];

void add(int x, int y){
    adj[x].push_back(y);
    ind[y]++;
}

void top_sort(){
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++){
        if(a[i] != -1 && !ind[a[i]]) q.push(a[i]);
    }
    while(q.size()){
        int t = q.top();
        q.pop();
        ans.push_back(t);
        for(int i = 0; i < adj[t].size(); i++){
            int u = adj[t][i];
            if(--ind[u] == 0) q.push(u);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        if(a[i] == -1) continue;
        if(a[i] % n != i){
            int ori = a[i] % n;
            if(ori < i){
                for(int j = ori; j < i; j++) add(a[j], a[i]);
            }else{
                for(int j = ori; j < n; j++) add(a[j], a[i]);
                for(int j = 0; j < i; j++) add(a[j], a[i]);
            }
        }
    }
    
    top_sort();
    for(auto x : ans) cout << x << ' ';
    return 0;
}