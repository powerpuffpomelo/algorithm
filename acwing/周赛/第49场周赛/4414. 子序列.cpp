// ###################################################### 版本2 ###################################################### //
// 可以更简洁，无需排序，甚至无需存储数组
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, x, s;
int a = -INF, b = INF;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > 0) s += x;
        if(x < 0 && x % 2) a = max(a, x);
        if(x > 0 && x % 2) b = min(b, x);
    }
    if(s % 2) cout << s << endl;
    else cout << max(s + a, s - b) << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int i = n - 1;
    int j1 = N, j2 = N;  // j1表示最小的正奇数，j2表示最大的负奇数
    while(i >= 0 && a[i] > 0){
        s += a[i];
        if(a[i] % 2) j1 = a[i];
        i--;
    }
    while(i >= 0 && a[i] % 2 == 0) i--;
    if(i >= 0) j2 = a[i];
    if(s % 2 == 0){
        s -= min(abs(j1), abs(j2));
    }
    cout << s << endl;
    return 0;
}