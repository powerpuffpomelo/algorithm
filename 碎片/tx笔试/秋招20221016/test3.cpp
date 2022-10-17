#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int, int> pii;
vector<pii> vv;

bool cmp(pii& a, pii& b){
    return a.second < b.second;
}

int main(){
    cin >> n;
    vv.resize(n);
    for(int i = 0; i < n; i++){
        cin >> vv[i].first >> vv[i].second;
    }
    sort(vv.begin(), vv.end());
    int xl = vv[n / 2 - 1].first + 1, xr = vv[n / 2].first - 1;
    if(xl > xr){
        cout << -1 << endl;
        return 0;
    }
    sort(vv.begin(), vv.end(), cmp);
    int yl = vv[n / 2 - 1].second + 1, yr = vv[n / 2].second - 1;
    if(yl > yr){
        cout << -1 << endl;
        return 0;
    }
    int s = 0;
    for(int i = 0; i < n; i++){
        if(vv[i].first < xl && vv[i].second < yl) s++;
    }
    if(s * 4 == n) cout << yl << ' ' << xl << endl;
    else cout << -1 << endl;
    
    return 0;
}