// ###################################################### 版本1 ###################################################### //
// O(n^2)

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N], dp[N];
int n, ans = 1;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] > ans) ans = dp[i];
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// O(n^2)

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int len2num[N], maxlen, n, x;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        int j = maxlen;
        while(len2num[j] >= x && j > 0) j--;
        len2num[j + 1] = x;
        maxlen = max(maxlen, j + 1);
    }
    cout << maxlen << endl;
    return 0;
}