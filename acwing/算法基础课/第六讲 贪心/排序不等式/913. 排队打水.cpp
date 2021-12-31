#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
long long ans = 0;
int a[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        ans += (a[i] * (n - i - 1));
    }
    cout << ans << endl;
    return 0;
}