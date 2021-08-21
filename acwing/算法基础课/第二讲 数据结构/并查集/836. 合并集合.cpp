#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int p[N];

int find(int a){
    if(p[a] != a) p[a] = find(p[a]);
    return p[a];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(op[0] == 'M') p[find(a)] = find(b);
        else{
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}