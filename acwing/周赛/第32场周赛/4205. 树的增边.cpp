#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx;
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// u是当前节点，c是要给当前节点染什么颜色，pa是从哪个节点过来的，防止回头重复
// 颜色有01两种，m是颜色为0的节点数量
// 就算不是从根节点开始搜索也没关系，也可以染到全部。
void dfs(int u, int c, int pa){
    if(!c) m++;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(j != pa){
            dfs(j, !c, u);
        }
    }
}

int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1, 0, 0);
    // 还能染多少，就是两组点的全连接数量，减去已有的点
    cout << (long long) m * (n - m) - (n - 1) << endl;  // long long只是加给m的，因为m * (n - m)已经爆int了，所以不能给答案整体转long long
    //printf("%lld\n", (long long) m * (n - m) - (n - 1));
    return 0;
}