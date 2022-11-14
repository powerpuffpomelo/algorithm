// 27%
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, t, k;
int h[N];
typedef pair<int, int> pii;
stack<pii> stk, kts;
//vector<int> h;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> h[i];
    while(m--){
        cin >> t >> k;
        while(stk.size() && k >= stk.top().second){
            stk.pop();
        }
        stk.push({t, k});
    }
    while(stk.size()){
        kts.push(stk.top());
        stk.pop();
    }
    while(kts.size()){
        auto to = kts.top();
        kts.pop();
        if(to.first == 1) sort(h, h + to.second);
        else sort(h, h + to.second, greater<int>());
    }
    for(int i = 0; i < n; i++) cout << h[i] << ' ';
    return 0;
}

// 82%
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, t, k;
int h[N];
typedef pair<int, int> pii;
stack<pii> stk, kts;
//vector<int> h;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> h[i];
    while(m--){
        cin >> t >> k;
        if(t == 1) sort(h, h + k);
        else sort(h, h + k, greater<int>());
    }
    for(int i = 0; i < n; i++) cout << h[i] << ' ';
    return 0;
}