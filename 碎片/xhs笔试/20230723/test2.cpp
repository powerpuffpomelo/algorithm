// 72%
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n, m, k, l, r;
vector<pair<LL, LL>> seg;

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        seg.push_back({l, r});
    }
    sort(seg.begin(), seg.end());
    LL ans = 0, temp = 0;
    deque<pair<int, int>> q;
    for(int i = 0; i < m; i++){
        int x = seg[i].first, y = seg[i].second;
        q.push_back(seg[i]);
        temp += y - x;
        int left = y - k;
        while(q.size() && q.front().second <= left){
            temp -= (q.front().second - q.front().first);
            q.pop_front();
        }
        if(q.size() && q.front().second > left && q.front().first < left){
            temp -= (left - q.front().first);
            q.pop_front();
            q.push_front({left, q.front().second});
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}