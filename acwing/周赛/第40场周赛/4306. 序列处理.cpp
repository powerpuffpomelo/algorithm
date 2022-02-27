// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
int n, a[N];
int ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 1; i < n; i++){
        while(a[i] <= a[i - 1]){
            a[i]++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}