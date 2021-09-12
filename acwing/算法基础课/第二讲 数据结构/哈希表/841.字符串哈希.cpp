#include <iostream>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;  //P进制
int n, m;
char str[N];
ULL h[N], p[N]; // h[N]存放字符串前缀哈希值，p[N]存放每位在P进制下代表多大的数

ULL cal(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(){
    scanf("%d%d%s", &n, &m, str + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    while(m--){
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(cal(l1, r1) == cal(l2, r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}