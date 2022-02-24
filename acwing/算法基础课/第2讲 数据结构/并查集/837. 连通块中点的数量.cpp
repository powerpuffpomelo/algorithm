#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int p[N], cnt[N]; //p[]存储每个节点在并查集中的父节点，cnt[]存储根节点所在连通块中点的数量

int root(int a){
    if(p[a] != a) p[a] = root(p[a]);
    return p[a];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        p[i] = i;
        cnt[i] = 1;
    } 
    while(m--){
        string op;
        int a, b;
        cin >> op;         // string类型不能用scanf读入
        if(op == "C"){
            scanf("%d%d", &a, &b);
            if(root(a) == root(b)) continue;
            cnt[root(b)] += cnt[root(a)];
            p[root(a)] = root(b);
        }else if(op == "Q1"){
            scanf("%d%d", &a, &b);
            if(root(a) == root(b)) puts("Yes");
            else puts("No");
        }else{
            scanf("%d", &a);
            printf("%d\n", cnt[root(a)]);
        }
    }
    return 0;
}