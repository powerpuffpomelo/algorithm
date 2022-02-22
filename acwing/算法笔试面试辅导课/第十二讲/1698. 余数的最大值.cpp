// 双向dfs
#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n, m, a[N];

void dfs(int id, int end, int s, vector<int> &vv){
    if(id == end){
        vv.push_back(s);
        return;
    }
    dfs(id + 1, end, s, vv);
    dfs(id + 1, end, (s + a[id]) % m, vv);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> vva, vvb;
    dfs(0, n / 2, 0, vva);
    dfs(n / 2, n, 0, vvb);
    sort(vva.begin(), vva.end());
    sort(vvb.begin(), vvb.end());
    // 第二段的最大值  m到2m-2
    int ans = (vva.back() + vvb.back()) % m;
    // 第一段的最大值  0到m-1
    for(int i = 0, j = vvb.size() - 1; i < vva.size() && j >= 0; i++){
        while(j >= 0 && vva[i] + vvb[j] >= m) j--;
        if(j >= 0) ans = max(ans, vva[i] + vvb[j]);
    }
    cout << ans << endl;
    return 0;
}