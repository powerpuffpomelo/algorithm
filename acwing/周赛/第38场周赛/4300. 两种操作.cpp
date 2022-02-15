// ###################################################### 版本4 ###################################################### //
// 贪心
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    cin >> n >> m;
    int ans = 0;
    while(m != n){
        if(m < n) m++;
        else if(m & 1) m++;
        else m /= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
// 用距离d 代替vis
// 在bfs中都可以，因为bfs是按距离从小到大vis的，所以只要vis过，即是最小距离
#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
int n, m;
int q[N], d[N], hh = 0, tt = -1;

int bfs(){
    fill(d, d + N, N);
    d[n] = 0;
    q[++tt] = n;
    while(hh <= tt){
        int t = q[hh++];
        int ha = t * 2, hb = t - 1;
        if(ha == m || hb == m) return d[t] + 1;  // 剪枝
        if(ha < N && d[ha] > d[t] + 1){
            d[ha] = d[t] + 1;
            q[++tt] = ha;
        }
        if(hb > 0 && d[hb] > d[t] + 1){
            d[hb] = d[t] + 1;
            q[++tt] = hb;
        }
    }
    //return d[m];   // 不剪枝
}

int main(){
    cin >> n >> m;
    cout << bfs() << endl;
    return 0;
}

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

const int N = 2e4 + 10;  // 只要开二倍大就可以了，因为如果n比m大则没必要*2 
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
