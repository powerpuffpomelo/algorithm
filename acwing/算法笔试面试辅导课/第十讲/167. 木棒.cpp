/*
剪枝：
1 按从大到小的顺序枚举木棍
2 木棒内部编号递增
3 跳过所有相等木棍
4 如果放第一个木棍失败了，则一定失败
5 如果放最后一个木棍失败了，则一定失败
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 65;
int n, a[N], sum, length, st[N];

// u 当前枚举到第几根木棒； cur 当前正在枚举的木棒长度； start 当前该从第几根木棍继续枚举
bool dfs(int u, int cur, int start){
    if(u * length == sum) return true;
    if(cur == length) return dfs(u + 1, 0, 0);
    for(int i = start; i < n; i++){
        if(st[i]) continue;
        int l = a[i];
        if(cur + l <= length){
            st[i] = 1;
            if(dfs(u, cur + l, i + 1)) return true;
            st[i] = 0;
        }
        if(!cur || cur + l == length) return false;
        int j = i + 1;
        while(j < n && a[j] == l) j++;
        i = j - 1;
    }
    return false;
}

int main(){
    while(cin >> n, n){
        sum = 0, length = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            length = max(length, a[i]);
        }
        sort(a, a + n);
        reverse(a, a + n);
        fill(st, st + n, 0);
        while(true){
            if(sum % length == 0 && dfs(0, 0, 0)){
                cout << length << endl;
                break;
            }
            length++;
        }
    }
    return 0;
}