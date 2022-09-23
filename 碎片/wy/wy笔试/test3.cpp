// 76.92% tle
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int a[N];
unordered_set<int> bit[35];    // 每位是1的数字存放
unordered_set<int> se;

void process(int u){
    for(int i = 0; i < 32; i++){
        if(a[u] >> i & 1) bit[i].insert(u);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        process(i);
        se.insert(i);
    }
    int ans = 0;
    
    for(int i = 31; i >= 0; i--){
        if(bit[i].size() < k) continue;
        unordered_set<int> temp;
        for(auto it = bit[i].begin(); it != bit[i].end(); it++){
            if(se.count(*it) && bit[i].count(*it)) temp.insert(*it);
        }
        if(temp.size() >= k){
            ans += 1 << i;
            se = temp;
        }
    }
    cout << ans << endl;
    return 0;
}
