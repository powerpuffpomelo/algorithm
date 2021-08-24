#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int p[N];

//找到根节点
int root(int a){
    if(p[a] != a) p[a] = root(p[a]); //路径压缩
    return p[a];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        char op[2];          // scanf读char的话，会读入空格回车；但是scanf读入字符串会忽略空格回车，所以这里用字符串
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(op[0] == 'M') p[root(a)] = root(b);
        else{
            if(root(a) == root(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}