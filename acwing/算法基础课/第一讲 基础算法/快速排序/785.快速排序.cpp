#include <iostream>
#include <algorithm>
using namespace std;

const int N=100010;
int n;
int q[N];

// 版本1
// 最后的情形貌似是，ij或者指向同一位置，或者j在i左边一格
void quick_sort(int q[], int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j){
        do i++; while(q[i] < x);   // 或者 while(q[++i] < x);   这里q[i]q[j]都必须 < > 而不能加 =
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}
// 版本1的另一种，版本1重点是：不能让递归的分支和递归前一致，否则报错
void quick_sort(int q[], int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r + 1 >> 1];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, i - 1);
    quick_sort(q, i, r);
}

// 版本2，容易理解，不会无限递归，但也容易退化到O(n^2)
void quick_sort_v2(int q[], int l, int r){
    if (l >= r) return;
    int i = l, j = r, x = q[l];
    while(i < j){
        while(i < j && q[j] > x) j--;   // 保证ij最后落在同一点
        q[i] = q[j];
        while(i < j && q[i] <= x) i++;
        q[j] = q[i];
    }
    q[i] = x;
    quick_sort(q, l, i - 1);
    quick_sort(q, i + 1, r);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n-1);
    for(int i=0; i<n; i++) printf("%d ", q[i]);
    return 0;
}