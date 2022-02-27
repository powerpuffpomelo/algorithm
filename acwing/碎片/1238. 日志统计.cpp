// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, d, k;
typedef pair<int, int> pii;
pii a[N];
unordered_map<int, int> cnt;
set<int> ans;

int main(){
    cin >> n >> d >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    for(int i = 0, j = 0; i < n; i++){
        int t = a[i].first, id = a[i].second;
        while(a[j].first <= t - d){
            cnt[a[j].second]--;
            j++;
        }
        cnt[id]++;
        if(cnt[id] >= k) ans.insert(id);
    }
    for(auto x : ans) cout << x << endl;
    return 0;
}