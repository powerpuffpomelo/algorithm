// 多路归并，可以转换成很多个二路归并
// O(mnlogn)
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2010;
int T, n, m;
int a[N], b[N], c[N];

void merge(){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i = 0; i < n; i++){
        q.push({b[i] + a[0], 0});
    }
    for(int i = 0; i < n; i++){
        auto t = q.top();
        q.pop();
        int v = t.first, p = t.second;
        c[i] = v;
        q.push({v - a[p] + a[p + 1], p + 1});
    }
    memcpy(a, c, sizeof(a));
}

int main(){
    cin >> T;
    while(T--){
        cin >> m >> n;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++) scanf("%d", &b[j]);
            merge();
        }
        for(int i = 0; i < n; i++) printf("%d ", a[i]);
        cout << endl;
    }
    return 0;
}