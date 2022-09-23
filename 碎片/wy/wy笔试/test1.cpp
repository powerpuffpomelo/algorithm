// 80%, tle
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1010;
int n, a[N];
int pos[N];
vector<pii> ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        while(a[i] != i){
            int to = pos[a[i] - 1];
            swap(pos[a[i]], pos[a[i] - 1]);
            swap(a[i], a[to]);
            ans.push_back({to, i});
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}
