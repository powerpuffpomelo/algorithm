#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;   // 从左指向右的邻接表，只记录一侧即可
int match[N];                 // 右对左的匹配
int st[N];                    // 宣告对右侧的占领权，防止死循环
int n1, n2, m;
int ans;

void add(int u, int v){
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

bool find(int u){
    for(int j = h[u]; j != -1; j = ne[j]){
        int v = e[j];
        if(!st[v]){
            st[v] = 1;
            if(match[v] == 0 || find(match[v])){    // 右点v暂无匹配，或者所匹配的左点可以find到其它点
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof(h));
    while(m--){
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for(int i = 1; i <= n1; i++){
        memset(st, 0, sizeof(st));
        if(find(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}