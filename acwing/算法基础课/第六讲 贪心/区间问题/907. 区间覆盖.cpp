// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int s, t, n, ans;
struct Range{
    int l, r;
    bool operator< (const Range &W)const{
        return l < W.l;
    }
}range[N];

int main(){
    cin >> s >> t;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
    sort(range, range + n);
    int i = 0, max_r = -2e9;
    while(s < t && i < n){
        while(range[i].l <= s && i < n){
            max_r = max(max_r, range[i].r);
            i++;
        }
        if(max_r > s){
            s = max_r;
            ans++;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    if(s >= t) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// yxc
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int st, ed, n, ans;
struct Range{
    int l, r;
    bool operator< (const Range &W)const{
        return l < W.l;
    }
}range[N];

int main(){
    cin >> st >> ed;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
    sort(range, range + n);
    bool success = false;
    for(int i = 0; i < n; i++){
        int j = i, r = -2e9;
        while(j < n && range[j].l <= st){
            r = max(r, range[j].r);
            j++;
        }
        if(r <= st) break;
        ans++;
        st = r;
        if(st >= ed){
            success = true;
            break;
        }
        i = j - 1;   // 跳过不必要的i，-1是为了和i++抵消
    }
    if(!success) ans = -1;
    cout << ans << endl;
    return 0;
}