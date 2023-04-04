/*
两个数组a和b，可以任意交换数组内元素位置，使得sum(ai-bi)^2最小
思路：sort
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
const int N = 1010;
int n;
int a[N], b[N];
lld ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for(int i = 0; i < n; i++){
        ans += pow(abs(a[i] - b[i]), 2);
    }
    cout << ans << endl;
    return 0;
}