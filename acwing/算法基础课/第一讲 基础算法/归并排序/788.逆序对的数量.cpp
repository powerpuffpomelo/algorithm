#include <iostream>
using namespace std;

typedef long long LL;  //注意数据范围

const int N=100010;
int n;
int q[N], temp[N];
LL ans=0;      //注意数值范围

// 版本1，直接操作全局变量ans
void merge_sort(int q[], int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid+1, r);
    int i = l, k = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else{
            ans += (mid - i + 1);   //想清楚思路再写
            temp[k++] = q[j++];
        }
    }
    while(i<=mid) temp[k++] = q[i++];
    while(j<=r) temp[k++] = q[j++];
    for(int i=l;i<=r;i++) q[i] = temp[i];
}

// 版本2， 返回ans
LL merge_sort_v2(int q[], int l, int r){
    if(l >= r) return 0; //忘记
    int mid = l + r >> 1;
    LL ans = merge_sort_v2(q, l, mid) + merge_sort_v2(q, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else{
            temp[k++] = q[j++];
            ans += mid - i + 1;  //思路
        } 
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    for(int i = l; i <= r; i++) q[i] = temp[i];
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &q[i]);
    merge_sort(q, 0, n-1);
    printf("%lld\n", ans);
    return 0;
}