#include <bits/stdc++.h>
using namespace std;

int T, n, a, b;

int main(){
    cin >> T;
    while(T--){
        cin >> n >> a >> b;
        if(abs(a - b) < n){
            cout << (n - 1 - abs(a - b)) / 2 + max(a, b) << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}