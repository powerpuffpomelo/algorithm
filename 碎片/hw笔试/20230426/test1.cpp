// 100%
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, ind[N], ans;
vector<int> adj[N];

void add(int a, int b){
    adj[a].push_back(b);
    ind[b]++;
}

bool top_sort(){
    queue<int> q;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!ind[i]) q.push(i);
    }
    while(q.size()){
        int s = q.size();
        ans++;
        for(int i = 0; i < s; i++){
            auto t = q.front();
            q.pop();
            cnt++;
            for(int j = 0; j < adj[t].size(); j++){
                int u = adj[t][j];
                if(--ind[u] == 0) q.push(u);
            }
        }
    }
    if(cnt == n) return true;
    else return false;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x;
        for(int j = 0; j < x; j++){
            cin >> y;
            add(y, i);
        }
    }
    if(top_sort()) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}