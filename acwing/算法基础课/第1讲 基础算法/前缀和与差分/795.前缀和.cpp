#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], s[N];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);    //从1开始数组，对于前缀和而言方便理解
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    while (m--){    // m个询问
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}