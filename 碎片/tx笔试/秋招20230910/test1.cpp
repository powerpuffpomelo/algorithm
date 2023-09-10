#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
string a, b;

int main(){
    cin >> n >> m >> a >> b;
    set<char> sea, seb;
    for(auto c : a) sea.insert(c);
    for(auto c : b){
        if(seb.count(c)) continue;
        if(sea.count(c)) ans++;
        seb.insert(c);
    }
    cout << ans << endl;
    return 0;
}