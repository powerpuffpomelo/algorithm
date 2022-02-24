// 贪心，如果【加入什么】不好考虑，可以考虑【去掉什么】
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n;

int main(){
    while(cin >> n){
        vector<pii> vv(n);
        for(int i = 0; i < n; i++) cin >> vv[i].second >> vv[i].first;
        sort(vv.begin(), vv.end());
        priority_queue<int, vector<int>, greater<int>> heap;
        for(auto p : vv){
            heap.push(p.second);
            if(heap.size() > p.first) heap.pop(); // 如果超期就去掉当前利润最低的
        }
        int ans = 0;
        while(heap.size()) ans += heap.top(), heap.pop();
        cout << ans << endl;
    }
    return 0;
}