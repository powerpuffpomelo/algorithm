// 固定中间，两侧独立搜索
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3010, INF = 1e9;
int n;
int s[N], c[N];
int res = INF;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int j = 0; j < n; j++){
        int ci = INF;
        for(int i = 0; i < j; i++){
            if(s[i] < s[j]) ci = min(ci, c[i]);
        }
        int ck = INF;
        for(int k = j + 1; k < n; k++){
            if(s[k] > s[j]) ck = min(ck, c[k]);
        }
        res = min(res, c[j] + ci + ck);
    }
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}