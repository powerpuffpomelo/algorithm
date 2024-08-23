#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 4e5 + 10, INF = 1e9 + 10;
int n, k; 
int a[N];
ll ans;
int global_vis[N];

void dfs(int ed, int remain, ll sum, ll& ret, vector<int>& vis, vector<int>& path, vector<int>& global_path){
    if(remain == 0){
        if(sum > ret){
            ret = max(ret, sum);
            global_path = path;
        }
        return;
    }
    for(int i = 1; i <= 4; i++){
        if(!vis[i - 1] && i <= remain){
            vis[i - 1] = 1;
            int next_id = ed - remain + i;
            path.push_back(next_id);
            ll next_sum = ((global_vis[next_id] == 0) ? sum + a[ed - remain + i] : sum);
            dfs(ed, remain - i, next_sum, ret, vis, path, global_path);
            path.pop_back();
            vis[i - 1] = 0;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i + n] = a[i + 2 * n] = a[i + 3 * n] = a[i];
    }
    int x = k / 4, y = k % 4;
    if(x){
        for(int i = 10; i <= 4 * n; i += 10){
            vector<int> vis(4);  // 是否用过 1234
            ll ret = -INF;
            vector<int> path, global_path;
            dfs(i, 10, 0, ret, vis, path, global_path);
            for(int p : global_path){
                int q = p % n;
                while(q <= 4 * n){
                    global_vis[q] = 1;
                    q += n;
                }
            }
            ans += ret * x;
        }
    }
    for(int i = 10; i <= y * 10; i += 10){
        vector<int> vis(4);  // 是否用过 1234
        ll ret = -INF;
        vector<int> path, global_path;
        dfs(i, 10, 0, ret, vis, path, global_path);
        for(int p : global_path){
            int q = p % n;
            while(q <= 4 * n){
                global_vis[q] = 1;
                q += n;
            }
        }
        ans += ret;
    }
    cout << ans << endl;
    return 0;
}
