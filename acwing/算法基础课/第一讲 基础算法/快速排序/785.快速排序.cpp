#include <iostream>
using namespace std;

const int N=100010;
int n;
int q[N];

void quick_sort(int q[], int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[l];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

void quick_sort_v2(int q[], int l, int r){
    if (l >= r) return;
    int i = l, j = r, x = q[l];
    while (i < j){
        while (i < j && q[j] > x) j--;
        q[i] = q[j];
        while (i < j && q[i] <= x) i++;
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