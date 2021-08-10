#include <iostream>
using namespace std;

const int N = 100010;
int n, q, k;
int arr[N];

int binary_search_1(int arr[], int l, int r, int k){
    while(l<r){
        int mid = l + r >> 1;
        if(arr[mid]>=k) r = mid;
        else l = mid + 1;
    }
    if(arr[l] == k) return l;
    else return -1;
}

int binary_search_2(int arr[], int l, int r, int k){
    while(l<r){
        int mid = l + r + 1 >> 1;  // 根据下方是否有mid-1来判断这里是否需要+1
        if(arr[mid]<=k) l = mid;
        else r = mid - 1;
    }
    if(arr[l] == k) return l;
    else return -1;
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    for(int i=0;i<q;i++){
        scanf("%d", &k);
        printf("%d %d\n", binary_search_1(arr, 0, n-1, k), binary_search_2(arr, 0, n-1, k));
        // 还有一种优化时间复杂度的方法，如果binary_search_1输出-1的话，就直接输出两个-1，不进行第二步搜索
    }
    return 0;
}