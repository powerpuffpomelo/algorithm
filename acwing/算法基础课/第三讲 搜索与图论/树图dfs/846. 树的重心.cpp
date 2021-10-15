#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
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
    dfs(1);
    cout << ans << endl;
    return 0;
}