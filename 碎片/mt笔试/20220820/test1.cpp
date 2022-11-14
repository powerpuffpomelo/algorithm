#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

int main(){
    cin >> n >> a >> b;
    string ans;
    for(int i = 0; i < n; i++){
        ans += a[i];
        ans += b[i];
    }
    cout << ans << endl;
    return 0;
}
