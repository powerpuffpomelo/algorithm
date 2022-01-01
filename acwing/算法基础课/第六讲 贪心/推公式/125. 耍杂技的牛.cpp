// ###################################################### 版本1 ###################################################### //
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50010;
int n, sum_now, ans = -0x3fffffff;
struct Cattle{
    int w, s;
    bool operator< (Cattle const &W)const{
        return w + s < W.w + W.s;
    }
}cattle[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> cattle[i].w >> cattle[i].s;
    sort(cattle, cattle + n);
    for(int i = 0; i < n; i++){
        ans = max(ans, sum_now - cattle[i].s);
        sum_now += cattle[i].w;
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50010;
typedef pair<int, int> PII;
PII cow[N];
int n, sum_now, ans = -2e9;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int w, s;
        cin >> w >> s;
        cow[i] = {w + s, s};
    }
    sort(cow, cow + n);
    for(int i = 0; i < n; i++){
        int w = cow[i].first - cow[i].second, s = cow[i].second;
        ans = max(ans, sum_now - s);
        sum_now += w;
    }
    cout << ans << endl;
    return 0;
}