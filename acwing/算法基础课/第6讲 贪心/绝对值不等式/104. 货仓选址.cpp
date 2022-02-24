// ###################################################### 版本1 ###################################################### //
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1;
    while(i < j){
        ans += a[j--] - a[i++];
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) ans += abs(a[i] - a[n / 2]);
    cout << ans << endl;
    return 0;
}