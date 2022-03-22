#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int T;
lld x, y;
queue<lld> q;
unordered_map<lld, lld> num;

lld cal(lld x, lld y){
    if(y >= x) return y - x;
    q.push(x);
    num[x] = 0;
    lld limit = LONG_MAX;
    if(limit / 9 > y) limit = y * 9;
    while(q.size()){
        lld t = q.front();
        q.pop();
        lld a = t + 1;
        if(!num.count(a)){
            num[a] = num[t] + 1;
            if(a == y) return num[y];
            q.push(a);
        }
        if(t % 3 == 0){
            lld a = t / 3;
            if(!num.count(a)){
                num[a] = num[t] + 1;
                if(a <= y) return num[a] + y - a;
                q.push(a);
            }
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> x >> y;
        cout << cal(x, y) << endl;
    }
    return 0;
}