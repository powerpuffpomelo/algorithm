// ###################################################### 版本2 ###################################################### //
// 更简洁一点
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], lv[N], rv[N];
int ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(a[i - 1] < a[i]) lv[i] = lv[i - 1] + 1;
        else lv[i] = 1;
    }
    for(int i = n; i; i--){
        if(a[i + 1] > a[i]) rv[i] = rv[i + 1] + 1;
        else rv[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(a[i - 1] < a[i + 1]) ans = max(ans, lv[i - 1] + rv[i + 1]);
        else ans = max(ans, max(lv[i - 1], rv[i - 1]));
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];
int lv[N], rv[N];
int ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ll = 0;
    for(int i = 1; i <= n - 1; i++){
        if(a[i] > a[i - 1]) ll++;
        else ll = 1;
        lv[i + 1] = ll;
    }
    ll = 0;
    for(int i = n; i >= 2; i--){
        if(a[i] < a[i + 1]) ll++;
        else ll = 1;
        rv[i - 1] = ll;
    }
    a[n + 1] = 2e5;
    for(int i = 1; i <= n; i++){
        if(a[i - 1] < a[i + 1]) ans = max(ans, lv[i] + rv[i]);
        else ans = max(ans, max(lv[i], rv[i]));
    }
    cout << ans << endl;
    return 0;
}