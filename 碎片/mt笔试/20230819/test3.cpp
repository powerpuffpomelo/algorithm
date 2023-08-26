// 100%
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
string str, a, b;
int n, ans;
int suma[N], sumb[N];

int main(){
    cin >> str;
    n = str.size();
    for(int i = 0; i < n; i++){
        if(i % 2) a += '1', b += '0';
        else a += '0', b += '1';
        suma[i + 1] = suma[i] + (str[i] == a[i] ? 0 : 1);
        sumb[i + 1] = sumb[i] + (str[i] == b[i] ? 0 : 1);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans += min(suma[j + 1] - suma[i], sumb[j + 1] - sumb[i]);
        }
    }
    cout << ans << endl;
    return 0;
}