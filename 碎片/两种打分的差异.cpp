// 21.05
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;  //注意数据范围
typedef pair<int, int> pii;

const int N=100010;
int n;
pii a[N], b[N];  // 输入的两种打分
map<int, int> mp; // 映射，从id值到位置
int q[N], temp[N];  // 求逆序对的数组，以及temp数组

bool cmp(pii x, pii y){
    return x.first > y.first;
}

// 归并排序
LL merge_sort(int q[], int l, int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    LL ans = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else{
            temp[k++] = q[j++];
            ans += mid - i + 1;
        } 
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    for(int i = l; i <= r; i++) q[i] = temp[i];
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].first;  // 第一个字段是打分的值
    for(int i = 0; i < n; i++) cin >> b[i].first;
    for(int i = 0; i < n; i++) a[i].second = b[i].second = i;  // 第二个字段是id，这里请把id填上
    
    sort(a, a + n, cmp); // 对a数组按照第一个字段从大到小排序
    for(int i = 0; i < n; i++){
        mp[a[i].second] = i;  // id数值映射到当前位置
    }
    
    sort(b, b + n, cmp); // 对b数组按照第一个字段从大到小排序
    for(int i = 0; i < n; i++){
        q[i] = mp[b[i].second];  // 取出位置，用于计算逆序对
    }
    
    LL ans = merge_sort(q, 0, n-1);
    cout << ans << endl;
    return 0;
}