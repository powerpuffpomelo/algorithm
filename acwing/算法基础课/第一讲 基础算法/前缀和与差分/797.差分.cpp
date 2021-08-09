//差分数组，就是前缀和数组中每两个相邻元素之差构成的数组

#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], s[N];  //a[N]是差分数组，s[N]是前缀和数组

void insert(int l, int r, int c){
    a[l] += c;
    a[r + 1] -= c;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
        insert(i, i, s[i]);      //差分数组也可以用函数解决
    }
    while (m--){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i++){
        a[i] += a[i - 1];
        printf("%d ", a[i]);
    }
    
    return 0;
}