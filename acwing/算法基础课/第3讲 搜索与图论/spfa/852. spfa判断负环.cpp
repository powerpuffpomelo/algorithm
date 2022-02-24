
/*
初始时将所有点插入队列中可以按如下方式理解：
在原图的基础上新建一个虚拟源点，从该点向其他所有点连一条权值为0的有向边。那么原图有负环等价于新图有负环。
此时在新图上做spfa，将虚拟源点加入队列中。
然后进行spfa的第一次迭代，这时会将所有点的距离更新并将所有点插入队列中。
执行到这一步，就等价于这里的做法了。

这题dist判断的逻辑是从负边出现时开始统计的，cnt 表示由第一次出现的负边起点做起点，该负边延伸的不改变负性的最大长度 
*/

// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2010, M = 10010;
int h[N], e[M], w[M], ne[M], idx;
int n, m;
int dist[N], inq[N], cnt[N];    // inq维护节点i是否在队列中；cnt维护超级源点到节点的最短路径包括的边数（不是条数）

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
        inq[i] = 1;
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        inq[t] = 0;
        for(int i = h[t]; i != -1; i = ne[i]){
            int v = e[i], d = w[i];
            if(dist[v] > dist[t] + d){
                dist[v] = dist[t] + d;
                cnt[v] = cnt[t] + 1;   // 这种cnt方式可以避免重边的影响；如果cnt用于记录一个节点被更新次数 则会因重边而错误
                if(cnt[v] >= n) return true;
                if(!inq[v]){
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    if(spfa()) puts("Yes");
    else puts("No");
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 没有inq似乎也可以！

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 2010, M = 10010;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
int n, m;

void add(int x, int y, int z){
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

bool spfa(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int v = e[i], d = w[i];
            if(dist[v] > dist[t] + d){
                dist[v] = dist[t] + d;
                cnt[v] = cnt[t] + 1;
                if(cnt[v] >= n) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    if(spfa()) puts("Yes");
    else puts("No");
    return 0;
}