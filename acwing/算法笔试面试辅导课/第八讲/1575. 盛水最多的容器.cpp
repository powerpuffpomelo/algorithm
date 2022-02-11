#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    int i = 1, j = n;
    int ans = 0;
    while(i < j){
        int area = min(h[i], h[j]) * (j - i);
        ans = max(ans, area);
        if(h[i] < h[j]) i++;
        else j--;
    }
    cout << ans << endl;
    return 0;
}