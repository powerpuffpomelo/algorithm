#include <bits/stdc++.h>
using namespace std;

int T;
int x, y, k;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    cin >> T;
    while(T--){
        cin >> x >> y >> k;
        int ret = 0;
        for(int i = 0; i <= k; i++){
            int a = x + i, b = y + k - i;
            ret = max(ret, gcd(a, b));
        }
        cout << ret << endl;
    }
    return 0;
}