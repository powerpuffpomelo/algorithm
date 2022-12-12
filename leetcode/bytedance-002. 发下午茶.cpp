// ###################################################### 版本1 ###################################################### //
// 我的初版，二分
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int k, n;
vector<int> a(N), b(N);

bool check(int t){
    b = a;
    for(int i = 1; i <= k; i++){
        int rem = t, p = 0;
        while(rem){
            if(p > n) return true;
            if(b[p]){
                int give = min(rem, b[p]);
                b[p] -= give;
                rem -= give;
            }else{
                rem--;
                p++;
            }
        }
    }
    if(b[n]) return false;
    return true;
}

int main(){
    cin >> k >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}