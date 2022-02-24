// 双指针算法，把O(N^2)复杂度化简为O(N)复杂度

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int arr[N], num[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        num[arr[i]]++;
        while(num[arr[i]] > 1){    // 出现重复
            num[arr[j]]--;
            j++;
        } 
        ans = max(ans, i - j + 1);
    }
    printf("%d\n", ans);
    return 0;
}
