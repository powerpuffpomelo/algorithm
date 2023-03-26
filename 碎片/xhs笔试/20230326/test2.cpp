#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t;
int n, k;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int i = 1, x = 1;
        for(int i = 1; i <= n; i++){
            if(a[i] == x) x++;
        }
        x--;
        int ret = (n - x) / k;
        if((n - x) % k) ret++;
        cout << ret << endl;
    }
    return 0;
}