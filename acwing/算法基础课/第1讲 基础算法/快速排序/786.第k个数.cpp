// ###################################################### 版本1 ###################################################### //
// 快速选择算法 时间复杂度O(n)
// 不同于快排，每次无需递归两边，只要递归一边就可以了
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n,k;
int q[N];

int quick_sort(int q[], int l, int r, int k){
    if(l >= r) return q[l];
    int i = l - 1, j = r + 1, x = q[l];
    while(i<j){
        do i++; while(q[i] < x);  //或者写成 while (q[++i] < x);
        do j--; while(q[j] > x);
        if(i<j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;     //左侧序列的长度
    if(sl >= k) return quick_sort(q, l, j, k);
    else return quick_sort(q, j+1, r, k - sl);
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &q[i]);
    printf("%d\n", quick_sort(q, 0, n-1, k));
    return 0;
}