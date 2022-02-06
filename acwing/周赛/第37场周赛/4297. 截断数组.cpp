// ###################################################### 版本2 ###################################################### //
// 优化版本
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 2e5 + 10;
int n;
lld s[N];
unordered_set<lld> se;  // 注意不要命名为hash

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        lld x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    for(int i = 0; i <= n; i++){
        se.insert(s[i]);
        lld s3 = s[n] - s[i];
        if(se.count(s3)){
            cout << s3 << endl;
            break;
        }
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 2e5 + 10;
lld arr[N], lsum[N], rsum[N];
int n;
lld ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) lsum[i] = lsum[i - 1] + arr[i];
    for(int i = n; i >= 1; i--) rsum[i] = rsum[i + 1] + arr[i];
    for(int i = 1, j = n; i < j;){
        if(lsum[i] == rsum[j]){
            ans = lsum[i];
            i++, j--;
        }else if(lsum[i] < rsum[j]){
            i++;
        }else{
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}
