// 100%
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, m, q, u;
string str;

int main(){
    cin >> n >> str;
    cin >> m;
    map<int, pair<string, string>> mp;
    for(int i = 1; i <= m; i++){
        string a, b;
        cin >> a >> b;
        mp[i] = {a, b};
    }
    cin >> q;
    while(q--){
        cin >> u;
        string a = mp[u].first, b = mp[u].second;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == '1') str[i] = '0';
            if(b[i] == '1') str[i] = '1';
            if(str[i] == '1') ans++;
        }
        cout << ans << endl;
    }
    return 0;
}