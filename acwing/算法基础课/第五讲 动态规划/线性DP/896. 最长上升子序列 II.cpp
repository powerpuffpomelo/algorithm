// ###################################################### 版本1 ###################################################### //
// O(nlogn)

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], len2num[N];  // len2num维护 长度为i的上升子序列末尾最小是什么数
int n, ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int l = 0, r = ans;   // l要从0开始，0代表a[i]不能跟在任何一个子序列后面
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(len2num[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len2num[r + 1] = a[i];   // 后来的数a[i]一定 <= 之前的len2num[r + 1]
        ans = max(ans, r + 1);
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 和版本1基本一致，其实无需记录a[i]
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, INF = 1e10;
int len2num[N], maxlen, n, x;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        int l = 0, r = maxlen;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(len2num[mid] < x) l = mid;
            else r = mid - 1;
        }
        len2num[l + 1] = x;
        maxlen = max(maxlen, l + 1);
    }
    cout << maxlen << endl;
    return 0;
}