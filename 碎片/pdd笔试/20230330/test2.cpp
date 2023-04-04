#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
vector<pii> adj[N];
int n, a, b, c;
set<int> donotneed;
set<int> all;

void dfs(int u, int pre, int temp){
    int tempcpy = temp;
    for(int i = 0; i < adj[u].size(); i++){
        pii j = adj[u][i];
        if(j.first == pre) continue;
        if(j.second == 1){
            all.insert(j.first);
            if(temp != -1){
                donotneed.insert(temp);
            }
            temp = j.first;
        }
        dfs(j.first, u, temp);
        temp = tempcpy;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int temp = -1;
    dfs(1, -1, temp);
    cout << all.size() - donotneed.size() << endl;
    return 0;
}