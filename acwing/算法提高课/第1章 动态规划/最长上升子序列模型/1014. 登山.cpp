// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, h[N], llis[N], rlis[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++){
        llis[i] = 1;
        for(int j = 1; j < i; j++){
            if(h[j] < h[i]) llis[i] = max(llis[i], llis[j] + 1);
        }
    }
    for(int i = n; i >= 1; i--){
        rlis[i] = 1;
        for(int j = n; j > i; j--){
            if(h[j] < h[i]) rlis[i] = max(rlis[i], rlis[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, llis[i] + rlis[i] - 1);
    }
    cout << ans << endl;
    return 0;
}