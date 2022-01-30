// ###################################################### 版本1 ###################################################### //
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = N * 2;  // M必须是2倍，因为无向图，每对点要构造两条边
int h[N], e[M], ne[M], idx;  // 数组模拟邻接表
int vis[N];  // 是否见过节点
int n, ans = N;

void add(int a, int b){  // 在ab两点之间连边
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

/*
这里dfs的理解：用dfs的方法来计算整颗树的节点数量（每棵树的节点都是所有子树节点数量之和+1），
在计算节点数量的时候，顺便算一下 当前节点能分开的子树的最大节点数，也就是顺便更新一下答案
*/
int dfs(int u){  // 返回以u为根节点的子树包含点数
    vis[u] = 1;
    int size = 0, sum = 1;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(vis[j]) continue;  // 防止往上走
        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum);  // 还要看子树上面的连通节点数
    ans = min(ans, size);
    return sum;
}

int main(){
    cin >> n;
    memset(h, -1, sizeof(h));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);  // 因为不知道题目怎么给，所以两边都要插
    }
    dfs(1);  // 其实有一个 根节点是1 这个假设
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 用pre替代vis
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, INF = 1e5 + 10;
int n;
int h[N], e[N * 2], ne[N * 2], idx;
int ans = INF;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int pre, int u){
    int sum = 1;
    int mm = 0;
    for(int i = h[u]; i != -1; i = ne[i]){
        int v = e[i];
        if(v != pre){
            int this_sum = dfs(u, v);
            mm = max(mm, this_sum);
            sum += this_sum;
        }
    }
    mm = max(mm, n - sum);
    if(mm < ans) ans = mm;
    return sum;
}

int main(){
    cin >> n;
    fill(h, h + N, -1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(-1, 1);
    cout << ans << endl;
    return 0;
}