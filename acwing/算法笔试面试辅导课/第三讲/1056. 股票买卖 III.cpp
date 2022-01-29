#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, INF = 2e9;
int n, arr[N];
int lv[N], rv[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 2, a_min = arr[1]; i <= n; i++){
        lv[i] = max(lv[i - 1], arr[i] - a_min);
        a_min = min(a_min, arr[i]);
    }
    for(int i = n - 1, a_max = arr[n]; i >= 1; i--){
        rv[i] = max(rv[i + 1], a_max - arr[i]);
        a_max = max(a_max, arr[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, lv[i] + rv[i]);
    }
    cout << ans << endl;
    return 0;
}